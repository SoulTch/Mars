#include <queue>
#include <map>

#include <core/hpp/mars/Game.hpp>
#include <core/hpp/mars/Events.hpp>
#include <core/hpp/mars/Interface.hpp>

using namespace MarsCore;

int numOfPlayers;
int generation;

MarsCore::Player player[MAX_PLAYER];
map<string, MarsCore::CorpArche> corpPool;
map<string, MarsCore::CardArche> cardPool;
vector<MarsCore::Project *> projectDeck;
vector<MarsCore::Project *> discardedDeck;

void loadCard() {

}

void initGame() {

}



void start() {
    initGame();
    startGame();
    bool f;
    do {
        generationBegin();

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

        f = generationEnd();
    } while(not f);

    finishGame();
}