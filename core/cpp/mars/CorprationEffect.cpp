#pragma once

#include <functional>

#include <core/hpp/mars/CardLoader.hpp>
#include <core/hpp/model/Entity.hpp>

using namespace std;
using namespace MarsCore;

map<string, Power<Corporation *>> loadCorporationPower() {
    map<string, Power<Corporation *>> m;
    Power<Corporation *> power;

    power.clear();
    power.addTask(Task());
    m["asd-123"] = power;

    
    power.clear();
    power.addTask(Task());
    m["sdf-453"] = power;

    return m;
}