#pragma once

#include <vector>
#include <map>

#include <core/hpp/model/Ability.hpp>

#include <core/hpp/model/Entity.hpp>
#include <core/hpp/model/Card.hpp>
#include <core/hpp/model/Resources.hpp>

using namespace std;

namespace MarsCore {



class Player {
public:
    struct Properties {
        // card cost
        int cardCost = 3;
        
        // basic project
        int sellPatentReward = 1;
        int buildPowerPlant = 1;
        int astroidStrike = 1;
        int buildAquifer = 1;
        int buildGreenery = 1;
        int buildCity = 1;

        // common project
        int regrowthGreenery = 1;
        int warmingCost = 1;
        int fundAwardReduction = 0;
        int milstoneCost = 1;

        // cost reduction
        int costDown = 0;
        int costDownTag[static_cast<int>(Tag::COUNT)] = {};

        // others
        bool resourcesVuln = false;
    } properties;

    Corporation corporation;
    vector<Project *> hand;
    vector<Ability *> abilities;

    int tags[static_cast<int>(Tag::COUNT)];
    int resources[static_cast<int>(Resources::COUNT)];
    int production[static_cast<int>(Resources::COUNT)];
    int idx;

    // Condition functions
    bool payable(int cost);
    bool has_hand();

    // Action functions
    void drawCard(int amount);
    template<typename Filter> vector<Project *> searchCard(int amount, Filter filter);
    void addCard(vector<Project *> &);

    vector<Project *> selectCard();
    void removeCard(const vector<Project *> &);

    void incTerraformingRating();
    
    void placeGreenery();
    void placeOcean();
    void placeCity();
    void incTemperature();
    
    void addResources(Resources restype, int amount);
    void subResources(Resources restype, int amount);
    void incProduction(Resources restype, int amount);
    void decProduction(Resources restype, int amount);
}; // class Player

} // namespace MarsCore

