#pragma once

#include <vector>

#include <core/hpp/model/Tasks.hpp>
#include <core/hpp/model/Log.hpp>

namespace MarsCore {

enum class IndicatorType {
    Oxygen,
    Ocean,
    Temperature,
    COUNT
};

class Indicator {
public:
    bool improvable();
    void improve(int, Log *);
    int needLevel(int);
    std::vector<Power<int>> bonus;

    bool acquired;
    bool activated;
    int initLevel;
    int maxLevel;
    int curLevel;
    int unitLevel;
};

class Surface {
public:
    Indicator *indicates[static_cast<int>(IndicatorType::COUNT)];
    bool isFinished();
};

}