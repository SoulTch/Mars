#pragma once

#include <functional>

#include <core/hpp/mars/CardLoader.hpp>

map<string, Power> loadProjectPower() {
    map<string, Power> m;
    Power power;


    power.clear();
    power.push_back(drawCardTask(2));
    m["asd-123"] = power;

    
    power.clear();
    power.push_back(drawCardTask(3));
    m["sdf-453"] = power;

    return m;
}