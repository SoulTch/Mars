#include <server/cpp/gameboard/game.hpp>
#include <server/jsonparser/json.hpp>
#include <iostream>

std::map<std::string, Power> projectEffect;
std::map<std::string, Power> corporationEffect;

void loadEffect() {
    loadProjectCard(projectEffect);
}

Json::json loadFile(string in) {
    std::ifstream in(filename);
    if (in) {
        in.seekg(0, std::ios::end);
        size_t len = in.tellg();
        in.seekg(0);

        std::string contents(len);
        in.read(&contents[0], len);
        
        return Json::parse(contents);
    } else {
        assert(false);
    }
}

void Game::startGame() {
    loadGame();
    gameStart();
    invokeEvent(new GameStartEvent());

    do {
        generation++;
        generationBegin();
        invokeEvent(new GenerationBeginEvent());

        int remain = numOfPlayers;
        bool finished[MAX_PLAYER];
        for (int i = 0; i < numOfPlayers; i++) finished[i] = false;

        int playerNum = currentGeneration%numOfPlayers;
        for (int playerNum = currentGeneration%numOfPlayers; remain > 0; playerNum = (playerNum+1)%numOfPlayers) {
            if (finisehd[playerNum]) continue;

            turnBegin(playerNum);
            invokeEvent(new TurnBeginEvent(playerNum));

            int actions = 2;
            while(actions > 0) {
                bool f = doAction(playerNum);
                if (not f) break;
                actions--;
                invokeEvent(new ActionDoneEvent(playerNum));
            }

            if (actions == 2) {
                remain -= 1;
                finished[playerNum] = true;
            }

            turnEnd(playerNum);
            invokeEvent(new TurnEndEvent(playerNum));
        }

        bool f = generationEnd();
        invokeEvent(new GenerationEndEvent();
    } while(!f);

    invokeEvent(new GameEndEvent());
    gameEnd();
}

void Game::invokeEvent(Event *event) {
    for (auto p = eventlistener.begin(); p != eventlistener.end(); ) {
        if (not p->onEvent(event)) {
            eventlistener.erase(p++);
        } else {
            p++;
        }
    }
}

bool Game::doAction(int playerNum) {
    vector<Action *> avail;
    for (auto &i : player[playerNum].actions) if (i->avail(this, playerNum)) {
        avail.push_back(i);
    }
    Action *action = chooseAction(playerNum, avail);

    if (action == nullptr) return false;
    action->play(this, playerNum);
    return true;
}

void Game::loadGame() {
    loadEffect();
    Json::json cardList = loadFile("project.json");
    Json::json corporationList = loadFile("corporation.json");

    for (auto i : cardList["cardlist"]) {
        if (i[expension] == "original") {
            projectDeck.push_back(Card(
                i["id"], 
                i["cost"], 
                i["point"], , 
                i["condition"], 
                i["require"], 
                i["tag"], 
                projectEffect[i["id"]]
            ));
        }
    }
    
    for (auto i : corporationList["cardlist"]) {
        if (i[expension] == "original") {
            corporationDeck.push_back(Corporation(
                i["id"], i["tag"], i["capital"], corporationEffect[i["id"]]
            ));
        }
    }

    indicator[Surfaces.temperature] = new TemperatureIndicator();
    indicator[Surfaces.oxygen]      = new OxygenIndicator();
    indicator[Sufraces.sea]         = new SeaIndicator();
    
    for (int i = 0; i < Surfaces.COUNT; i++) {
        if (indicator[i] == nullptr) indicatror[i] = new Indicator();
    }

    for (int i = 0; i < numOfPlayers; i++) {
        player[i].actions.push_back(new SellPatentAction());
        player[i].actions.push_back(new BuildPowerPlantAction());
        player[i].actions.push_back(new MeteorStrikeAction());
        player[i].actions.push_back(new ExtractWaterAction());
        player[i].actions.push_back(new BuildGreeneryAction());
        player[i].actions.push_back(new BuildCityAction());

        player[i].actions.push_back(new TreePlantingAction());
        player[i].actions.push_back(new WarmingAction());
    }
}

void Game::gameStart() {
    vector<Card *> cards[MAX_PLAYER];
    vector<Corporation *> corps[MAX_PLAYER];

    for (int i = 0; i < numOfPlayers; i++) {
        cards[i] = player[i].selectcard(i, 10, false);
        tie(cards[i], cops[i]) = player[i].choosecorporation(i, 2, cards[i]);
    }
}

void draft(Game *game) {
    for (int i = 0; i < game->numOfPlayers; i++) {
        game->player[i].shopcard(i, 4);
    }
}

void Game::generationBegin() {
    if (generation > 0) draft(this);
}

bool Game::generationEnd() {
    for(int i = 0; i < numOfPlayers; i++) {
        player[i].addResources(Resources.heat, player[i].resourcesowned[Resources.electricity]);
        player[i].setResources(player[i].resourcesowned[Resources.electricity], 0);

        for (int j = 0; j < Resources.COUNT; j++) {
            player[i].addResources(j, player[i].resourcesProduction(j));
        }
    }

    bool isFinished = true;
    for (int i = 0; i < Surfaces.COUNT; i++) {
        isFinished &= indicator[i].satisfied(this);
    }

    return isFinished;
}