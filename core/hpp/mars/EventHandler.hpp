#pragma once

#include <any>
#include <functional>

using namespace std;

namespace MarsCore {

enum class GlobalEvent {
    // Generation Event
    StartGame,
    FinishGame,
    GenerationBegin,
    GenerationEnd,
    COUNT
};

enum class Event {
    // Turn Event
    ActionDone,
    TurnBegin,
    TurnEnd,

    DrawCardEvent,
    AddCardEvent,
    ActionEndEvent,
    TurnEndEvent,
    COUNT
};

template<typename... V>
class EventHandler {
public:
    void addPrivateHandler(int player, const function<bool(V...)> &h) {
        priv[player].push_back(h);
    }

    void addPublicHandler(const function<bool(int, V...)> &h) {
        publ.push_back(h);
    }

    void invoke(int player, V... args) {
        priv[player].remove_if([&](auto &x) {return not x(args);});
        publ        .remove_if([&](auto &x) {return not x(player, args);});
    }

private:
    list<function<bool(V...)>>      priv[MAX_PLAYER];
    list<function<bool(int, V...)>> publ;
};

template<typename... V>
class GlobalEventHandler {
public:
    void addHandler(const function<bool(V...)> &h) {
        publ.push_back(h);
    }

    void invoke(int player, V... args) {
        publ.remove_if([&](auto &x) {return not x(args);});
    }

private:
    list<function<bool(V...)>> publ;
};

extern any globalh[static_cast<int>(GlobalEvent::COUNT)];
extern any handler[static_cast<int>(Event::COUNT)];

template<Event T, typename... V>
void addPrivateEventListener(int player, const function<bool(V...)>& handler) {
    any_cast<EventHandler<V...>>(handler[static_cast<int>(T)]).addPrivateHandler(handler);
}

template<Event T, typename V>
void addPublicEventListener(const function<bool(int, V...)>& handler) {
    any_cast<EventHandler<V...>>(handler[static_cast<int>(T)]).addPublicHandler(handler);
}

template<Event T, typename... V>
void invokeEvent(int player, V... args) {
    any_cast<EventHandler<V...>>(handler[static_cast<int>(T)]).invoke(player, args);
}

template<GlobalEvent T, typename... V>
void addGlobalEventLietener(const function<bool(V...)>& handler) {
    any_cast<GlobalEventHandler<V...>>(globalh[static_cast<int>(T)]).addHandler(handler);
}

template<GlobalEvent T, typename... V>
void invokeGlobalEvent(V... args) {
    any_cast<GlobalEventHandler<V...>>(globalh[static_cast<int>(T)]).invoke(args);
}


} // namespace MarsCore