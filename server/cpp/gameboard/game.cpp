#include <server/cpp/gameboard/game.hpp>
#include <server/jsonparser/json.hpp>
#include <iostream>

void Game::startGame() {
    loadGame();
    gameStart();
    invokeEvent(new GameStartEvent());

    do {
        currentGeneration++;
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
                finished[player] = true;
            }

            turnEnd(playerNum);
            invokeEvent(new TurnEndEvent(playerNum));
        }

        bool f = generationEnd();
        invokeEvent(new GenerationEndEvent();
    } while(f);

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

std::map<std::string, Power> projectEffect;
std::map<std::string, Power> corporationEffect;

void loadEffect() {
    loadProjectCard(projectEffect);
}


class OriginalGame : Game {
public:
    std::vector<Corporation> corporationDeck;

    void loadGame() {
        loadEffect();
        Json::json cardList = loadFile("project.json");

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

        Json::json corporationList = loadFile("corporation.json");
        
        for (auto i : corporationList["cardlist"]) {
            if (i[expension] == "original") {
                corporationDeck.push_back(Corporation(
                    i["id"], i["tag"], i["capital"], corporationEffect[i["id"]]
                ));
            }
        }
    }
};


