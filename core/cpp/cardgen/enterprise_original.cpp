#pragma once

#include <map>
#include <string>

#include <server/cpp/power.hpp>
#include <server/cpp/action.hpp>
#include <server/cpp/task.hpp>

void loadProjectCard(std::map<std::string, Power> &m) {
    Power power;

    power.clear();
    power.addTask(new DrawCardTask());
    m["abs-123"] = power;
}
