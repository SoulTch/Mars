#pragma once
#include <functional>

#include <core/hpp/model/Entity.hpp>

using namespace std;

namespace MarsCore {
class Enchantment {
public:
    function<void(Entity *)> enable;
    function<void(Entity *)> disable;
};
} // namespace MarsCore