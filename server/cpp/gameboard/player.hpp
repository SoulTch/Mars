#pragma once

#include <vector>

#include <server/cpp/playable/playable.hpp>
#include <server/cpp/playable/tag.hpp>

class Player {
    Enterprise *enterprise;
    std::vector<Card *> hand, played;

    int MCperSteel = MC_PER_STEEL;
    int MCperTitanium = MC_PER_TITANIUM;
    int tagsOwned[Tag.COUNT];
    int resourcesOwned[Resources.COUNT];
    int resourcesProduction[Resources.COUNT];
};