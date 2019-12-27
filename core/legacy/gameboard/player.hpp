#pragma once

#include <vector>

#include <server/cpp/playable/playable.hpp>
#include <server/cpp/playable/tag.hpp>

class Player {
    Game *game;
    Enterprise *enterprise;
    std::vector<Card *> hand, played;
    std::vector<Action *> actions;
    std::list<EventListener> eventlistener;

    int tagsOwned[Tag.COUNT];
    int resourcesOwned[Resources.COUNT];
    int resourcesProduction[Resources.COUNT];


    int cardBuyCost = 3;
    void cardBuyBehavior(std::vector<Card *> cand);
    void cardBuyBehavior(int amount);

    std::vector<EventHandler> eventHandler[Signal.COUNT];
};