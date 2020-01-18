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
    int id;
    EntityType entity_type;
    EnabledEnchant enableEnchant(Enchantment *pt);
    void disableEnchant(EnabledEnchant it);

private:
    static int _id;
    std::list<Enchantment *> enchants;
    std::list<Enchantment *> aura;
}; // class Entity


} // namespace MarsCore