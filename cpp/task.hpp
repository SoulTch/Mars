#ifndef _TASK_HPP__
#define _TASK_HPP__

#include "game.hpp"

class Task {
public:
    void (*run)(Game &game, int player);
};



















#endif