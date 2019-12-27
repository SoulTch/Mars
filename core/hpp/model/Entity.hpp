// [HPP file for Entity]
// entity - all objects which can be targetted by any effect
// 

#pragma once
#include <list>
#include <core/hpp/model/Enchantment.hpp>

namespace MarsCore {
using EnabledEnchant = std::list<Enchantment *>::iterator;

enum class EntityType {
    Project,
    Basic
};

class Entity {
public:
    EntityType entity_type;
    EnabledEnchant enableEnchant(Enchantment *pt);
    void disableEnchant(EnabledEnchant it);

private:
    std::list<Enchantment *> enchants;
    std::list<Enchantment *> aura;
}; // class Entity


template<typename... T>
class Task {
public:
    function<void(T)> activate;
    function<bool(T)> available;
    function<void(T)> play;
};

template<typename T>
class Power {
public:
    vector<function<void(T)>> activate;
    vector<function<bool(T)>> available;
    vector<function<void(T)>> play;

    void addTask(const Task &);
    void clear();
};

} // namespace MarsCore