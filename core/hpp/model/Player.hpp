#pragma once

#include <vector>
#include <map>
#include <set>

#include <core/hpp/model/Ability.hpp>
#include <core/hpp/model/Entity.hpp>
#include <core/hpp/model/Card.hpp>
#include <core/hpp/model/Resources.hpp>

namespace MarsCore {



class Player {
public:
    struct Properties {
        Enchantable<int> cardCost = 3;
        Enchantable<int> basicProject[6] = {
            1, 11, 14, 18, 23, 25
        };

        Enchantable<int> regrowth = 8;
        Enchantable<int> warming = 8;
        
        Enchantable<int> fundAwardReduction = 0;
        Enchantable<int> milestone = 8;

        // others
        bool resourcesVuln = false;
		bool startupFree = false;
    } properties;


    Corporation *corporation;
    std::set<Project *> hand;
	json enabledEffect;

    AbilityGroup abilities[static_cast<int>(AbilityType::COUNT)];

    int terraforminRating;
    int tags[static_cast<int>(Tag::COUNT)];
    int resources[static_cast<int>(Resources::COUNT)];
    int production[static_cast<int>(Resources::COUNT)];
    int idx;

}; // class Player

} // namespace MarsCore