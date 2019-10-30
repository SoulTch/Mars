#pragma once

#include <vector>
#include <list>
#include <server/cpp/gameboard/player.hpp>
#include <server/cpp/event/event.hpp>

#define MAX_PLAYER 5

class Game {
public:
    int numOfPlayers;
    int generation;
    Player player[MAX_PLAYER];

    Indicator *surface[Surface.COUNT];

    std::vector<Card> projectDeck;
    std::vector<Card> discardedDeck;
    std::vector<Corporation> corporationDeck;
    std::list<EventListener> eventlistener;

    Game(Expension expension);
    void startGame(); // TODO :: link with queue
    void invokeEvent(Event *event);

    void loadGame();
    void gameStart();
    void turnStart(int playerNumber);
    void doAction(int playerNumber);
    void turnEnd(int playerNumber);
    void generationBegin();
    bool generationEnd();

};