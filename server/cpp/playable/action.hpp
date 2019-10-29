#pragma once

enum ActionState {
    STATE_DISABLED, STATE_AVAILABLE, STATE_TERMINATED
};

class Action {
public:
    virtual bool avail(Game *game, Player *promoter) { return true; }
    virtual bool play(Game *game, Player *promoter) { return true; }
    ActionState getState() {return state;}
protected:
    void disable();
    void enable();
    void terminate();
private:
    ActionState state;
};

class PlayCardAction : Action {

};

class BuildGreeneryAction : Action {

};