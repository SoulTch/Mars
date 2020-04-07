#pragma once

#include <functional>

using namespace std;

namespace MarsCore {

enum class Event {
    // Generation Event
    StartGame,
    FinishGame,
    GenerationBegin,
    GenerationEnd,

    // Turn Event
    ActionDone,
    TurnBegin,
    TurnActionEnd,
    TurnEnd,

    AddCard,
    RemoveCard,
    PlayCard,

    IncTerraforming,
    AddResources,
    SubResources,
    IncProduction,
    DecProduction,

    COUNT
};

class EventHandler {
public:
    template<typename T>
    void addPrivateHandler(int player, const function<bool(T&)> &h) {
        static_cast<Wrapper<T> *>(this)->addPrivateHandler(player, h);
    }

    template<typename T>
    void addPublicHandler(const function<bool(T&)> &h) {
        static_cast<Wrapper<T> *>(this)->addPublicHandler(h);
    }

    template<typename T>
    void invoke(const T &param) {
        static_cast<Wrapper<T> *>(this)->invoke(player, param);
    }

    template<typename T>
    class Wrapper : public EventHandler {
    public:

        void addPrivateHandler(int player, const function<bool(T&)> &h) {
            priv[player].push_back(h);
        }

        void addPublicHandler(const function<bool(T&)> &h) {
            publ.push_back(h);
        }

        
        void invoke(const T &param) {
            priv[param.player].remove_if([&](auto &x) {return not x(param);});
            publ              .remove_if([&](auto &x) {return not x(param);});
        }

    private:
        list<function<bool(T&)>> priv[MAX_PLAYER];
        list<function<bool(T&)>> publ;    
    };
};


template<Event E, typename T>
void addPrivateEventListener(int player, const function<bool(T&)>& handler) {
    static_cast<EventHandler::Wrapper<T> &>(handler[static_cast<int>(E)]).addPrivateHandler(player, handler);
}

template<Event E, typename T>
void addPublicEventListener(const function<bool(T&)>& handler) {
    static_cast<EventHandler::Wrapper<T> &>(handler[static_cast<int>(E)]).addPublicHandler(handler);
}

template<Event E, typename T>
void invokeEvent(const T &param) {
    static_cast<EventHandler::Wrapper<T> &>(handler[static_cast<int>(E)]).invoke(param);
}

extern EventHandler *handler[static_cast<int>(Event::COUNT)];

} // namespace MarsCore

