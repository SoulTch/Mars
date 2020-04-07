#include <core/hpp/model/Surface.hpp>

namespace MarsCore {

bool Indicator::improvable() {
    if (not activated) return false;
    return curLevel < maxLevel;
}

void Indicator::improve(int player, Log *l) {
    curLevel += unitLevel;
    bonus[curLevel/unitLevel].run(&player, l);
}

int Indicator::needLevel(int level) {
    if (not activated) return 1000;
    
    int x = (level-curLevel) / unitLevel;

    if (x < 0) return 0;
    return x;
}

bool Surface::isFinished() {
    for (int i = 0; i < static_cast<int>(IndicatorType::COUNT); i++) {
        if (indicates[i]->activated and 
            indicates[i]->acquired  and
            not indicates[i]->improvable())
            return false;
    }
    return true;
}


}