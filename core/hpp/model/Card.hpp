#pragma once

#include <string>
#include <vector>
#include <functional>
#include <utility>

#include <core/hpp/model/Entity.hpp>
#include <core/hpp/mars/CardLoader.hpp>

using namespace std;

namespace MarsCore {

enum class CardType {
    Automated, Event
};

enum class State {
    Ready, Hand, Field, Closed
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


class CardArche {

};

class CorpArche : public CardArche {
public:
    string id;
    string name;
    int tag[10];
}; // class CorpArche

class ProjectArche : public CardArche {
public:
    string id;
    string name;

}; // class CardArche

class Card {
public:
    string id;
    string name;
    int tag[10];
    int owner;
}; // class Card

class Corporation : public Card {
public:
    
};

class Project : public Card, public Entity {
public:
    State state;
};






} // namespace MarsCore

