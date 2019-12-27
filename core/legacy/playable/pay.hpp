#pragma once

#include <string>

class Payment {
public:
    virtual int available(Game *game, Player *player) = 0;
};

class ProjectPayment : Payment {
public:
    Card *project;
};

class ActionPayment : Payment {
public:
    Action *project;
};




