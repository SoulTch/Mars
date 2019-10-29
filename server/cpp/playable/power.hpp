#pragma once

#include <vector>
#include "task.hpp"

class Power {
public:
    void clear() {
        enchant.clear();
        task.clear();
    }

    void addEnchant(Task *en) {
        enchant.push_back(en);
    }

    void addTask(Task *ta) {
        task.push_back(ta);
    }

    void appendPower(Power *pow) {
        for (auto i : pow->enchant) addEnchant(i);
        for (auto i : pow->task)    addTask(i); 
    }

private:
    std::vector<Task *> enchant;
    std::vector<Task *> task;
};