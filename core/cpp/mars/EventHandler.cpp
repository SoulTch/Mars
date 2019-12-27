#include <list>

#include <core/hpp/mars/EventHandler.hpp>
#include <core/hpp/mars/Game.hpp>

using namespace MarsCore;
using namespace std;

any globalh[static_cast<int>(GlobalEvent::COUNT)] = {

};

any handler[static_cast<int>(Event::COUNT)] = {
    EventHandler<int>()
};