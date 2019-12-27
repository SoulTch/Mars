#pragma once

#include <vector>
#include "tag.hpp"
#include "event.hpp"

class Playable {
public:
    const std::string id;
    int tag[Tag.COUNT];
    int res[Counter.COUNT];
    std::vector<Task> tasks;
};

class Card : Playable {
public:
    const int cost;
    const int point;
    const ProjectType type;
    std::vector<Task> onLoad;

    Card(
        std::string id,
        int cost, 
        int point, 
        ProjectType type, 
        Json::json condition, 
        Json::json require, 
        Json::json tag, 
        Power effect) : id(id), cost(cost), point(point), type(type) {
        
        power.addTask(new PaymentTask(cost, this, ));
        for (auto i : condition.obj) {
            power.addTask(new ConditionTask(mSurface[i.second["target"]], i.second["dir"] == "<=", i.second["value"]));
        }
        for (auto i : require.obj) {
            power.addTask(new RequireTask(mTag[i.second["target"]], i.second["dir"] == "<=", i.second["value"]));
        }
        power.appendTask(effect);
        for (auto i : tag.obj) {
            tag[(int)mTag[i.first]] = i.second;
        }
        if (cost != 0) power.addTask(new GainPointTask(this, cost));
    }

    std::vector<Enchant *> enchant;
};

class Corporation : Playable {
public:
    Corporation (std::string id, Json::json tag, int capital, Power effect) {
        power.apendTask(effect);
        for (auto i : tag.obj) {
            tag[(int)mTag[i.first]] = i.second;
        }
        power.addTask(new ResourceGainTask(Resources.megacredit, capital));
    }
}; 