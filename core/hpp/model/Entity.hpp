// [HPP file for Entity]
// entity - all objects which can be targetted by any effect
// 

#pragma once
#include <list>
#include <functional>
#include <string>

namespace MarsCore {

template<typename T>
class Enchantment {
public:
	std::string detail;
    virtual void enable(T *) = 0;

	Enchantment(const std::string& detail) : detail(detail) { }

	virtual ~Enchantment() = default;
};



template<typename T>
class Aura {
public:
	std::string detail;
    virtual void enable(T *) = 0;
    virtual void disable(T *) = 0;

	Aura(const std::string& detail);
};

template<typename T>
class Entity {
public:
	using EnabledEnchant = typename std::list<Enchantment<T> *>::iterator;
    using EnabledAura = typename std::list<Aura<T> *>::iterator;

    EnabledEnchant enableEnchant(Enchantment<T> *pt) {
        pt->enable(static_cast<T *>(this));
		enchants.push_back(pt);
		return std::prev(enchants.end());
    }

    EnabledAura enableAura(Aura<T> *pt) {
        pt->enable(static_cast<T *>(this));
        aura.push_back(pt);
		return std::prev(aura.end());
    }

    void disableAura(EnabledAura it) {
        *it->disable(static_cast<T *>(this));
        aura.erase(it);
    }

private:
    std::list<Enchantment<T> *> enchants;
    std::list<Aura<T> *> aura;
}; // class Entity

template<typename T>
class Enchantable : public Entity<Enchantable<T>> {
public:
    Enchantable(const T& val) : val(val) { }
    Enchantable(T &&val) : val(std::move(val)) { }
    operator T&() {
        return val;
    }

	Enchantable<T> &operator=(const T& v) {
		val = v;
		return *this;
	}
private:
    T val;
};


} // namespace MarsCore