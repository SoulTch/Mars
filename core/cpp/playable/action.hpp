#pragma once

#include <vector>

class Action {
public:
    virtual bool avail(Game *game, Player *promoter) { return true; }
    virtual bool play(Game *game, Player *promoter) { return true; }
    std::vector<Payment *> payments;
};

class PlayCardAction : Action {

};

class BuildGreeneryAction : Action {

};