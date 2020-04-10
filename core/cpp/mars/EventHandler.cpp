#include <list>

#include <core/hpp/mars/EventHandler.hpp>
#include <core/hpp/mars/Game.hpp>

using namespace MarsCore;
using namespace std;

EventHandler *MarsCore::handler[static_cast<int>(Event::COUNT)];