#pragma once

#include <vector>

using namespace std;

enum class Indicator {
    Oxygen,
    Ocean,
    Temperature,
    COUNT
};

class Surface {
public: 
    static const int inds = static_cast<int>(Indicator::COUNT);
    int level[inds];
    int goal [inds];

    bool improvable(Indicator indtype);
    void improve(Indicator indtype, int promoter);
};