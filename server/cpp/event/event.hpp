#pragma once

#include "game.hpp"
#include "player.hpp"

class Event {
public:
    virtual void run(Game *game, Log *log) = 0;
};

class EventListener {
public:
    virtual void onEvent(Game *game, Log *log, Event *event) = 0;
};

class DrawCardEvent : public Event {
public:
    DrawCardEvent(int amount) : amount(amount) { }
    void run(Game *game, Log *log) {
        
    }
private:
    Player *player;
    int amount;
};