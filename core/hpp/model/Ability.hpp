#pragma once

#include <functional>
#include <nlohmann/json.hpp>

#include <core/hpp/model/Entity.hpp>

using json = nlohmann::json;

namespace MarsCore {

enum class AbilityType {
    PlayCard,
    Standard,
    Milestore,
    Award,
    Greenery,
    Temperature,
    Instant,
    COUNT
};


class Activatable {
public:
    int owner;
    AbilityType type;
    bool available();
    void set_validity(bool);

    virtual void revalidate() = 0;
    virtual void run(json &l) = 0;

private:
    bool is_avail = false;
};

class InstantAbility : public Activatable {
public:
    std::function<bool(int)> _reval;
    std::function<void(int, json &)> _run;

    InstantAbility(std::function<bool(int)> _reval, std::function<void(int, json &)> _run);

    void revalidate() override;
    void run(json &) override;
};

class AbilityGroup : public std::list<Activatable *> {
public:
    void refresh(int);

private:
    int era = -1;
};


}