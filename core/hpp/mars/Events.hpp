#pragma once

#include <vector>

#include <core/hpp/model/Card.hpp>

namespace MarsCore {

struct SimpleEvent {
    int player;
};

struct CardEvent {
    int player;
    std::vector<Project *> const *cards;
};

struct PlayProjectEvent {
    int player;
    Project *card;
};

struct ResourcesEvent {
    int player;
    int target;
    Resources restype;
    int amount;
};


}