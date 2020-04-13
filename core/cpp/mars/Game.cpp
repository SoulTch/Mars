#include <queue>
#include <map>
#include <fstream>
#include <random>

#include <nlohmann/json.hpp>

#include <core/hpp/model/Milestone.hpp>
#include <core/hpp/model/Reward.hpp>

#include <core/hpp/mars/Game.hpp>
#include <core/hpp/mars/Events.hpp>
#include <core/hpp/mars/Interface.hpp>
#include <core/hpp/mars/CardLoader.hpp>

using namespace MarsCore;
using json = nlohmann::json;

int numOfPlayers;
int generation;
string datapath;
string maptile;

json mapinfo;

Player player[MAX_PLAYER];
map<string, CorpArche> corpArcheMap;
map<string, ProjectArche> cardArcheMap;

MilestoneManager milestone;
RewardManager award;
Surface surface;
Board board;

vector<Corporation *> corporationDeck;
queue<Project *> projectDeck;
vector<Project *> discardedDeck;

random_device rd;
mt19937 rng(rd());


void initGame() {
	for (int i = 0; i < numOfPlayers; i++) {
		player[i].idx = i;
	}

	corpArcheMap = loadCorporationArche(datapath+"/corporation.json");
	cardArcheMap = loadProjectArche(datapath+"/project.json");

	ifstream is(datapath+"/"+maptile);
	is >> mapinfo;
	is.close();

	for (json &code : mapinfo["corporation-list"]) {
		corporationDeck.push_back(new Corporation(&corpArcheMap[(const string&)code]));
	}

	for (json &code : mapinfo["deck-list"]) {
		discardedDeck.push_back(new Project(&cardArcheMap[(const string&)code]));
	}

	shuffle(corporationDeck.begin(), corporationDeck.end(), rng);
	shuffle(discardedDeck.begin(), discardedDeck.end(), rng);
	reload();

	milestone.setMilestone(mapinfo["milestone"]);
	award.setAward(mapinfo["award"]);
	surface.setBonus(mapinfo["bonus"]);
	board.setBoard(mapinfo["board"]);

	initComplete();
}

void firstStep() {
	vector<array<Corporation *, 2>> corps(numOfPlayers);
	vector<vector<Project *>> prjs(numOfPlayers, vector<Project *>(10));

	for (int i = 0; i < numOfPlayers; i++) {
		for (int j = 0; j < 2; j++) {
			corps[i][j] = corporationDeck[i*2+j];
		}
		for (int j = 0; j < 10; j++) {
			prjs[i][j] = projectDeck.front();
			projectDeck.pop();
		}
	}

	vector<Corporation *> selcorp = selectStartup(corps, prjs);

	for (int i = 0; i < numOfPlayers; i++) {
		setCorporation(i, selcorp[i]);
	}

	shopCardAsync(prjs);

    startGame();
}

void refreshGeneration() {
	json log = {
		{"event-type", "generation begin"},
		{"issuer", -1},
		{"sub-log", "[]"_json }
	};

	for (int i = 0; i < numOfPlayers; i++) {
		addResources(&log, i, Resources::Megacredit, player[i].terraforminRating);
		for (int j = 0; j < static_cast<int>(Resources::COUNT); j++) {
			addResources(&log, i, static_cast<Resources>(j), player[i].production[j]);
		}
	}

	vector<vector<Project *>> prjs(numOfPlayers, vector<Project *>(4));

	for (int i = 0; i < numOfPlayers; i++) {
		for (int j = 0; j < 4; j++) {
			prjs[i][j] = seekCard();
		}
	}

	shopCardAsync(prjs);
	generationBegin();
}

bool finishGeneration() {
	generationEnd();

	return surface.isFinished();
}

void start() {
	initGame();
	firstStep();
    bool f;
    do {
		refreshGeneration();
        int remain = numOfPlayers;

        queue<int> q;
        int firstPlayer = generation%numOfPlayers;
        for (int i = 0; i < numOfPlayers; i++) {
            q.push((firstPlayer+i)%numOfPlayers);
        }

        while(q.size() > 0) {
            int cur = q.front(); q.pop();
            turnBegin(cur);

            int actions = 2;
            while(actions > 0) {
                bool f = doAction(cur);
                if (not f) break;
                actions--;
                actionDone(cur);
            }

            if (actions < 2) {
                q.push(cur);
            }

            turnEnd(cur, actions < 2);
        }

		f = finishGeneration();
    } while(not f);

    finishGame();
}








// mars_core datapath maptile player_num
int main(int argc, char *argv[]) {
	datapath = argv[1];
	numOfPlayers = atoi(argv[2]);
	start();
}