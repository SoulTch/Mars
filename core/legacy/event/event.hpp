#pragma once

#include "game.hpp"
#include "player.hpp"

enum class Signal {
    DrawCardEvent,
    AddCardEvent,
    COUNT
};

enum class GlobalSignal {
    ActionEndEvent,
    TurnEndEvent
    COUNT
};


class Event {

}

class EventHandler {
    virtual void run(Event *event) { };
};


class DrawCardEvent : Event {
    
};