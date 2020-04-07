// [HPP file for Entity]
// entity - all objects which can be targetted by any effect
// 

#pragma once
#include <list>

namespace MarsCore {

template<typename T>
class Enchantment {
public:
    virtual void enable(T *) = 0;

    template<typename V>
    class Instance : public Enchantment<Instance<V>> {
    public:
        V obj;
        Instance(V &&obj) : obj(obj) { }
        void enable(T *arg) { obj(arg); }
    };
};

template<typename T>
class Aura {
public:
    virtual void enable(T *) = 0;
    virtual void disable(T *) = 0;

    template<typename U, typename V>
    class Instance : public Aura<Instance<U, V>> {
    public: 
        U v1;
        V v2;
        Instance(U &&v1, V &&v2) : v1(v1), v2(v2) { }
        void enable(T *arg) { v1(arg); }
        void disable(T *arg) { v2(arg); }
    };
};

template<typename T>
class Entity {
public:
    using Enabled = typename std::list<Enchantment<T> *>::iterator;

    void enableEnchant(Enchantment<T> *pt) {
        pt->enable(static_cast<T *>(this));
    }

    Enabled enableAura(Enchantment<T> *pt) {
        pt->enable(static_cast<T *>(this));
        return enchants.push_back(pt);
    }

    void disableAura(Enabled it) {
        *it->disable(static_cast<T *>(this));
        aura.erase(it);
    }

private:
    std::list<Enchantment<T> *> enchants;
    std::list<Enchantment<T> *> aura;
}; // class Entity

template<typename T>
class Enchantable : public Entity<Enchantable<T>> {
public:

    Enchantable(T &&val) : val(val) { }
    operator T() {
        return val;
    }
private:
    T val;
};


} // namespace MarsCore