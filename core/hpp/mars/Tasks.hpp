#pragma once

#include <string>
#include <map>

#include <core/hpp/model/Card.hpp>
#include <core/hpp/model/Entity.hpp>
#include <core/hpp/model/Surface.hpp>
#include <core/hpp/model/Resources.hpp>
#include <core/hpp/model/Tasks.hpp>

using namespace std;
using namespace MarsCore;

// Project Task


template<typename V, typename T>
V getv(T &v) {
    if constexpr (is_same_v(V, T)) {
        return v;
    } else {
        return v();
    }
}

template<typename A, typename T> 
Task<A> drawCardTask(T &&amount) {
    return {
        nullopt,
        [=](const Activate<A> &act) {
            player[act.player].drawcard(getv<int>(amount));
        }
    };
}

template<typename A, typename T>
Task<A> shopCardTask(T &&amount) {
    return {
        nullopt,
        [=](const Activate<A> &act) {
            player[act.player].drawcard(getv<int>(amount));
        }
    };
}

// SurfaceTask
Task incTemperatureTask();
Task placeOceanTask();
Task incOxygenTask();

Task requireSurfaceTask(Indicator, bool);

// Tile task
Task placeTileTask(string);
Task placeCityTask();
Task placeGreeneryTask();

// Production Task
template<typename A, typename T>
Task<A> needProductionTask(Resources r, T &&func) {
    return {
        [=](const Activate<A> &act) {
            if constexpr (is_same_v<int, decay_t<T>>) {
                return player[act.player].production[static_cast<int>(r)] >= func;
            } else {
                return func(player[act.player].production[static_cast<int>(r)]);
            }
        },
        nullopt
    };
};

template<typename A, typename T>
Task<A> decAnyProductionTask(Resources r, T &&func) {
    return {
        [=](const Activate<A> &act) {
            int need = getv<int>(amount);
            return any_of(player, player+numOfPlayers, [](const auto &p) {
                return func(p.production[static_cast<int>(r)]);
            });
        },
        [=](const Activate<A> &act) {

        }
    };
}

template<typename A, typename T>
Task<A> incProductionTask(Resources r, T &&amount) {
    return {
        nullopt,
        [=](const Activate<A> &act) {
            player[act.player].incProduction(r, getv<int>(amount));
        }
    };
}

template<typename A, typename T>
Task<A> decProductionTask(Resources r, T &&amount) {
    return {
        [=](const Activate<A> &act) {
            return r == Resources::Megacredit or getv<int>(amount) <= player[act.player].production[static_cast<int>(r)];
        },
        [=](const Activate<A> &act) {
            player[act.player].decProduction(r, getv<int>(amount));
        }
    }
}

// Resources Task
Task paymentTask(Resources, int);

template<typename A, typename T>
Task<A> addResourcesTask(Resources r, T &&amount) {
    return {
        nullopt,
        [=](const Activate<A> &act) {
            player[act.player].addResources(r, getv<int>(amount));
        }
    };
}


Task subAnyResourcesTask(Resources, int);

// Project Resources Task
Task addProjectResourcesTask(ResourcesCounter, bool, int);

// Special Task