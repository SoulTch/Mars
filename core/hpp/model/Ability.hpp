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
    Project *target;
    bool available() override;
    int play() override;
};

class PersistActionAbility : public Ability {
    Card *target;
    Power task;

    bool available() override;
    int play() override;
};

class InstantAbility : public Ability {
    bool available() override;
    int play() override;
};

class BasicProjectAbility : public Ability {
    BasicProject *target;

    bool available() override;
    int play() override;
};

class GreeneryAbility : public Ability {
    bool available() override;
    int play() override;
};

class WarmingAbility : public Ability {
    bool available() override;
    int play() override;
};

class FundAwardAbility : public Ability {
    bool available() override;
    int play() override;
};

class MilestoneAbility : public Ability {
    bool available() override;
    int play() override;
};