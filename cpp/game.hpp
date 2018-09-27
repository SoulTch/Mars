#ifndef _GAME_HPP__
#define _GAME_HPP__

#include <vector>
#include <set>
#include <queue>
#include <map>
#include <memory.h>

typedef unsigned int PID;

class Game;

enum class ProjectType {persistent, normal, event, passive, company, Count};
enum class TagType {science, animal, building, space, Count};
enum class ActionType {no_action, only_one, dontcare};
enum class ResourceType {megacredit, iron, titanium, plant, electricity, heat, Count};

class Tag {
public:
    int v[(int)(TagType::Count)];
    Tag();
    Tag(...);
};


class Project {
public:
    ProjectType ptype;
    ActionType atype;
    int cost;
    Tag req_tag;
    Tag prv_tag;

    bool (*require)(Game &game, int player, ...);
    void (*propel)(Game &game, int player, ...);
    void (*afterProject)(Game &game, int player, PID played, int amount);
};

class PersistentProject : public Project {
public:
    int (*discounts)(Game &game, int player, PID played, int amount);
    bool (*action_require)(Game &game, int player, ...);
    bool (*action_propel)(Game &game, int player, ...);
};

class CompanyProject: public PersistentProject {

};

class EventProject: public Project {

};

class NormalProject: public Project {

};

class PassiveProject: public Project {
public:
    bool (*passive_require)(Game &game, int player, ...);
    bool (*passive_propel)(Game &game, int player);
};

class DummyProject: public Project {

};


class Game {
public:
    int idx;


    class BehaviorBlock {
    public:
        Project &Project;
        bool hasPlayed;
        Tag resource;
    };

    class Player {
    public:
        bool allpass;

        int terraformingGrade;
        int score;
        
        int megaCredit, dMegaCredit;
        int iron, dIron;
        int titanium, dTitanium;
        int plant, dPlant;
        int electricity, dElectricity;
        int heat, dHeat;
        
        Tag tags;
        std::set<PID> hand;
        std::queue<PID> actionQueue;

        std::map<PID, BehaviorBlock> canTrigger;
        std::set<PID> playedProject;
        std::set<PID> normalProject;

        Player();
        ~Player();
    };

    std::vector<Player> players;
    int temperature;
    int venusLevel;
    int oxygen;
    int waterpool;

    int generation;
    int turn;
    int remainAction;

    Game();
    ~Game();

    

    std::set<PID> deck;
    std::set<PID> grave;

    PID seekCard();
    PID drawCard();
    void discard(PID id);
    void buyCard(PID id, int cost);  
};

void LoadCardList();
extern std::map<PID, Project> cardList;


#endif