#pragma once

#include <core/hpp/model/Entity.hpp>
#include <vector>

using namespace std;

namespace MarsCore {

class Activate {
    Entity *entity;
};

class Task {
public:
    optional<function<bool(const Activate &)>> available;
    optional<function<void(const Activate &)>> play;
};

class Power {
public:
    void addTask(const Task &);
    void clear();

private:
    vector<bool(const Activate &)> available;
    vector<void(const Activate &)> play;
};

}