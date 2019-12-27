#pragma once

class Enchant {
public:
    std::string id;
    virtual void enable(Game *game, Player *player, Playable *target) = 0;
    virtual void disable(Game *game, Player *player, Playable *target) = 0;
};

class ReduceCostEnchant : Enchant {
    
};