#pragma once

#include <functional>

#include <core/hpp/mars/CardLoader.hpp>
#include <core/hpp/mars/Tasks.hpp>

map<string, Power> loadProjectPower() {
    map<string, Power> m;
    map<string, Power> p;

    Power power;
    Power ____p;


    power.clear();
    m.emplace("ori-001", power);

    
    power.clear();
    power.addTask(needProductionTask(Resources::Titanium, 1));
    power.addTask(decAnyProductionTask(Resources::Titanium, 1));
    power.addTask(incProductionTask(Resources::Titanium, 1));
    m.emplace("ori-002", power);

    power.clear();
    power.addTask(incProductionTask(Resources::Electricity, 1));
    power.addTask(incTemperatureTask());
    m.emplace("ori-003", power);

    power.clear();
    power.addTask(decProductionTask(Resources::Megacredit, 1));
    power.addTask(decAnyProductionTask(Resources::Heat, 1));
    power.addTask(incProductionTask(Resources::Plant, 2));
    m.emplace("ori-004", power);

    power.clear();
    ____p.clear();
    ____p.addTask(paymentTask(Resources::Megacredit, 1));
    ____p.addTask({
        nullopt,
        [](const Activate &act){
            Card *v = getCard();
            if (v->tag[static_cast<int>(Tag::Microbe)] > 0) {
                
            }
        }
    });
    m.emplace("ori-005", power);
    p.emplace("ori-005", ____p);

    power.clear();
    ____p.clear();
    ____p.addTask(shopCardTask(1));
    m.emplace("ori-006", power);
    p.emplace("ori-006", ____p);

    power.clear();
    ____p.clear();
    ____p.addTask(paymentTask(Resources::Electricity, 1));
    ____p.addTask(addResourcesTask(Resources::Megacredit, [](){return 3;}));
    m.emplace("ori-007", power);
    p.emplace("ori-007", ____p);


    power.clear();
    power.addTask(decProductionTask(Resources::Electricity, 2));
    power.addTask(incProductionTask(Resources::Megacredit, 5));
    power.addTask(placeCityTask());
    m.emplace("ori-008", power);

    power.clear();
    power.addTask(incTemperatureTask());
    power.addTask(addResourcesTask(Resources::Titanium, 2));
    power.addTask(subAnyResourcesTask(Resources::Plant, 3));
    m.emplace("ori-009", power);

    power.clear();
    power.addTask(incTemperatureTask());
    power.addTask(placeOceanTask());
    power.addTask(subAnyResourcesTask(Resources::Plant, 3));
    m.emplace("ori-010", power);

    return m;
}