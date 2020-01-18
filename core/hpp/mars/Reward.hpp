#pragma once

#include <core/hpp/model/Player.hpp>

using namespace std;

#define MAX_REWARD 5

class Reward {
public:
    string code;
    bool occupied = false;
    function<int(Player *)> getPoint;
};

class RewardManager {
public:
    int maxreward = 3;
    int made = 0;
    int cost[MAX_REWARD] = {8, 12, 20};
    Reward rewards[MAX_REWARD];
};