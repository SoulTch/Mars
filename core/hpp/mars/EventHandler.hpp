#pragma once

#include <functional>

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

template<typename T>
class HandlerWrapper;

class EventHandler {
public:
    template<typename T>
    void addPrivateHandler(int player, const std::function<bool(T&)> &h) {
        static_cast<HandlerWrapper<T> *>(this)->addPrivateHandler(player, h);
    }

    template<typename T>
    void addPublicHandler(const std::function<bool(T&)> &h) {
        static_cast<HandlerWrapper<T> *>(this)->addPublicHandler(h);
    }

    template<typename T>
    void invoke(int player, const T &param) {
        static_cast<HandlerWrapper<T> *>(this)->invoke(player, param);
    }
};

template<typename T>
class HandlerWrapper : public EventHandler {
public:
	void addPrivateHandler(int player, const std::function<bool(const T&)> &h) {
		priv[player].push_back(h);
	}

	void addPublicHandler(const std::function<bool(const T&)> &h) {
		publ.push_back(h);
	}

	
	void invoke(const T &param) {
		priv[param.player].remove_if([&](auto &x) {return not x(param);});
		publ              .remove_if([&](auto &x) {return not x(param);});
	}

private:
	std::list<std::function<bool(const T&)>> priv[5];
	std::list<std::function<bool(const T&)>> publ;    
};

extern EventHandler *handler[static_cast<int>(Event::COUNT)];

template<Event E, typename T>
void addPrivateEventListener(int player, const std::function<bool(const T&)>& _handler) {
    static_cast<HandlerWrapper<T> *>(handler[static_cast<int>(E)])->addPrivateHandler(player, _handler);
}

template<Event E, typename T>
void addPublicEventListener(const std::function<bool(const T&)>& _handler) {
    static_cast<HandlerWrapper<T> *>(handler[static_cast<int>(E)])->addPublicHandler(_handler);
}

template<Event E, typename T>
void invokeEvent(const T &param) {
    static_cast<HandlerWrapper<T> *>(handler[static_cast<int>(E)])->invoke(param);
}


} // namespace MarsCore

