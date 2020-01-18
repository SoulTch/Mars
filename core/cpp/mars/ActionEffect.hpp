#pragma once

#include <functional>

#include <core/hpp/mars/CardLoader.hpp>

map<string, Power> loadActionPower() {
    map<string, Power> m;

    Power power;

    power.clear();
    power.addTask(paymentTask(Resources::Megacredit, 1));
    power.addTask(addProjectResourcesTask(ResourcesCounter::Science, true, 1));
    m["ori-005"] = power;

    power.clear();
    power.addTask(shopCardTask(1));
    m["ori-006"] = power;

    power.clear();
    power.addTask(paymentTask(Resources::Electricity, 1));
    power.addTask(addResourcesTask(Resources::Megacredit, 3));
    m["ori-007"] = power;
    

    return m;
}