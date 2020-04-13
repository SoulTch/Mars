#pragma once

#include <vector>

#include <core/hpp/model/Player.hpp>

using namespace std;
using namespace MarsCore;

#define MAX_MILESTONE 5

class Milestone {
public:
    string code;
    bool occupied = false;
    function<bool(Player *)> available();
};

class MilestoneManager {
public:
    int remainMilestone;
    Milestone milestones[MAX_MILESTONE];
};

