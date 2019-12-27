#pragma once

#include <core/hpp/model/Entity.hpp>

using namespace std;
using namespace MarsCore;

class Ability {
public:
    virtual bool available() = 0;
    virtual int play() = 0;
};

class PlayCardAbility : public Ability {

};

class PersistActionAbility : public Ability {

};

class InstantAbility : public Ability {
    
};

class BasicProjectAbility : public Ability {
    
};

class GreeneryAbility : public Ability {

};

class WarmingAbility : public Ability {

};

class FundAwardAbility : public Ability {

};

class MilestoneAbility : public Ability {

};