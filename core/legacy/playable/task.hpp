#pragma once

#include <string>

class Task {
public:
    virtual bool require(Game *game, Player *player) { };
    virtual bool run(Game *game, Player *player, bool random) { };
};

class Point {
public:
    int point;
    std::string message;
};

class PointCalculate {
public:
    virtual Point calcPoint(Game *game, Player *player) = 0;
};

class DrawCardTask : public Task {
public:
    bool run(Game *game, Player *player, bool random) { 
        
    }
};