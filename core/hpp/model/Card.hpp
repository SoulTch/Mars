#pragma once

#include <string>
#include <vector>
#include <functional>
#include <utility>
#include <variant>

#include <core/hpp/model/Entity.hpp>
#include <core/hpp/model/Point.hpp>
#include <core/hpp/model/Resources.hpp>
#include <core/hpp/model/Tasks.hpp>
#include <core/hpp/model/Ability.hpp>

namespace MarsCore {

enum class CardType {
    Automated, Event
};

enum class Tag {
    Building,
    Space,
    Science,
    Plant,
    Microbe,
    Animal,
    Power,
    Jovian,
    Earth,
    City,
    Event,
    Venus,
    Wild,
    COUNT
};

class Project;
class Corporation;
class Card;

class CardArche {
public:
    std::string id;
    int tag[static_cast<int>(Tag::COUNT)];
    
    std::variant<std::monostate, Point, std::function<Point(Card *)>> point;
};

class CorpArche : public CardArche {
public:
    int startingMC;
    Power<Corporation> base, power;
}; // class CorpArche

class ProjectArche : public CardArche {
public:
    int cost;
    Power<Project> base, power;
}; // class CardArche

class Card : public Activatable {
public:
    StackResources restype;
    int resources;
    bool resourceRemovable;
}; // class Card

class Corporation : public Card, public CorpArche {
public:
    void revalidate() override;
    void run(Log *) override;
};

class Project : public Card, public ProjectArche, public Entity<Project> {
public:
    CardType type;
    int costReduced;
    int additionalTag[static_cast<int>(Tag::COUNT)];

    void revalidate() override;
    void run(Log *l) override;
};

class PermanentAbility : public Activatable {
public:
    Card *target;
    Power<Card> power;

    PermanentAbility(Card *target, Power<Card> &&power);

    void revalidate() override;
    void run(Log *l) override;
};


} // namespace MarsCore

