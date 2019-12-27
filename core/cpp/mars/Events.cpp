#include <core/hpp/mars/Events.hpp>
#include <core/hpp/mars/EventHandler.hpp>

using namespace MarsCore;

void startGame() {
    invokeGlobalEvent<GlobalEvent::StartGame>();
}

void finishGame() {
    invokeGlobalEvent<GlobalEvent::FinishGame>();
}

void generationBegin() {
    invokeGlobalEvent<GlobalEvent::GenerationBegin>();
}

bool generationEnd() {
    invokeGlobalEvent<GlobalEvent::GenerationEnd>();

    return false;
}

bool doAction(int player) {

}

void actionDone(int player) {
    invokeEvent<Event::ActionDone>(player);
}

void turnBegin(int player) {
    invokeEvent<Event::TurnBegin>(player);
}

void turnEnd(int player, bool end) {
    invokeEvent<Event::TurnEnd>(player, end);
}



