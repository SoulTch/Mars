#pragma once

#include <vector>

#include <core/hpp/model/Ability.hpp>

#include <core/hpp/model/Entity.hpp>
#include <core/hpp/model/Card.hpp>

using namespace std;

namespace MarsCore {
class Player {
public:
    Corporation corporation;
    vector<Project *> hand;
    vector<Ability *> abilities;

    int tags[static_cast<int>(Tag::COUNT)];

    int idx;
    bool payable(int cost);
    bool has_hand();

    
    
}; // class Player
} // namespace MarsCore

