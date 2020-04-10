#pragma once

#include <string>
#include <vector>
#include <functional>
#include <utility>
#include <variant>
#include <nlohmann/json.hpp>

#include <core/hpp/model/Entity.hpp>
#include <core/hpp/model/Point.hpp>
#include <core/hpp/model/Resources.hpp>
#include <core/hpp/model/Tasks.hpp>
#include <core/hpp/model/Ability.hpp>

using json = nlohmann::json;

namespace MarsCore {

enum class CardType {
    Automated, Active, Event
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

    Point point;
};

class CorpArche : public CardArche {
public:
    int startingMC;
    Power<Corporation> base, power;

	CorpArche(const std::string& id, const json& arc, Power<Corporation> power);
}; // class CorpArche

class ProjectArche : public CardArche {
public:
    int cost;
    Power<Project> base, power;

	ProjectArche(const std::string& id, const json& arc, Power<Project> power);
}; // class CardArche

class Card : public Activatable {
public:
	int player;
    StackResources restype;
    int resources;
    bool resourceRemovable;
}; // class Card

class Corporation : public Card {
public:
    CorpArche *arche;

	Corporation();
	Corporation(CorpArche *);
    void revalidate() override;
    void run(Log *) override;
};

class Project : public Card, public Entity<Project> {
public:
    ProjectArche *arche;
    int costReduced;
    int additionalTag[static_cast<int>(Tag::COUNT)];

	Project();
	Project(ProjectArche *);
    void revalidate() override;
    void run(Log *l) override;
};

class PermanentAbility : public Activatable {
public:
    Card &target;
    Power<Card> power;

    PermanentAbility(Card &target, Power<Card> &&power);

    void revalidate() override;
    void run(Log *l) override;
};


} // namespace MarsCore

