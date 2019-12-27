#pragma once
#include <functional>

#include <core/hpp/model/Entity.hpp>

using namespace std;

namespace MarsCore {
class Aura {
public:
    function<void(Entity *)> enable;
    function<void()> disable;
};
} // namespace MarsCore