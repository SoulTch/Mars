#pragma once

#include <vector>
#include <list>
#include <server/cpp/gameboard/player.hpp>
#include <server/cpp/event/event.hpp>

#define MAX_PLAYER 5
#define CARD_BUY_COST 3
#define MC_PER_STEEL 2
#define MC_PER_TITANIUM 3




class Game {
public:
    int numOfPlayers;
    int currentGeneration;
    Player player[MAX_PLAYER];

    std::vector<Card> projectDeck;
    std::vector<Card> discardDeck;
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

    std::vector<Card *> shopCard(std::vector<Card *> cand, Player *player);
    Player *selectPlayer(Player *player, bool (*chk)(Game *, Player *));
    Playable *selectCard(Player *player, bool (*chk)(Game *, Player *, Playable *));
    
};

class OriginalGame : Game;