#include <core/hpp/mars/Interface.hpp>
#include <core/hpp/mars/EventHandler.hpp>
#include <core/hpp/mars/Events.hpp>



using MarsCore::Event;

void startGame() {
	


    SimpleEvent ev;
    MarsCore::invokeEvent<Event::StartGame>(ev);
}

void finishGame() {
    SimpleEvent ev;
    MarsCore::invokeEvent<Event::FinishGame>(ev);
}

void generationBegin() {
    SimpleEvent ev;
    MarsCore::invokeEvent<Event::GenerationBegin>(ev);
}

bool generationEnd() {
    SimpleEvent ev;
    MarsCore::invokeEvent<Event::GenerationEnd>(ev);
	return false;
}

void actionDone(int player) {
    SimpleEvent ev;
    MarsCore::invokeEvent<Event::ActionDone>(ev);
}

void turnBegin(int player) {
    SimpleEvent ev;
    MarsCore::invokeEvent<Event::TurnBegin>(ev);
}

void turnEnd(int player, bool end) {
    SimpleEvent ev;
    MarsCore::invokeEvent<Event::TurnEnd>(ev);

    if (end) {
        SimpleEvent ev;
        MarsCore::invokeEvent<Event::TurnActionEnd>(ev);
    }
}

// Action functions
vector<Project *> seekCard(int amount) {
    int sel = min(amount, (int)projectDeck.size());
    vector<Project *> ret(projectDeck.begin(), next(projectDeck.begin(), sel));
    projectDeck.erase(projectDeck.begin(), next(projectDeck.begin(), sel));
    amount -= sel;

    if (amount > 0) {
        reload();
        int sel = min(amount, (int)projectDeck.size());
        ret.insert(ret.end(), projectDeck.begin(), next(projectDeck.begin(), sel));
        projectDeck.erase(projectDeck.begin(), next(projectDeck.begin(), sel));
    }

    return ret;
}

void addCard(int p, const vector<Project *> &t) {
    CardEvent ev;
    ev.player = p;
    ev.cards = &t;

    player[p].hand.insert(t.begin(), t.end());
    MarsCore::invokeEvent<Event::AddCard>(ev);
}

void drawCard(int p, int amount) {
    addCard(p, seekCard(amount));
}

void removeCard(int p, const vector<Project *> & t) {
    for (auto &x : t) {
        player[p].hand.erase(x);
    }
    CardEvent ev;
    ev.player = p;
    ev.cards = &t;
    MarsCore::invokeEvent<Event::RemoveCard>(ev);
}

void incTerraformingRating(int p) {
    player[p].terraforminRating += p;
    
    SimpleEvent ev;
    ev.player = p;
    MarsCore::invokeEvent<Event::IncTerraforming>(ev);
}

void addResources(int p, int target, Resources restype, int amount) {
    player[target].resources[static_cast<int>(restype)] += amount;

    ResourcesEvent ev;
    ev.player = p;
    ev.target = target;
    ev.restype = restype;
    ev.amount = amount;

    MarsCore::invokeEvent<Event::AddResources>(ev);
}

void subResources(int p, int target, Resources restype, int amount) {
    int &t = player[target].resources[static_cast<int>(restype)];
    amount = min(amount, t);
    t -= amount;

    ResourcesEvent ev;
    ev.player = p;
    ev.target = target;
    ev.restype = restype;
    ev.amount = amount;

    MarsCore::invokeEvent<Event::SubResources>(ev);
}

void incProduction(int p, int target, Resources restype, int amount) {
    player[target].production[static_cast<int>(restype)] += amount;

    ResourcesEvent ev;
    ev.player = p;
    ev.target = target;
    ev.restype = restype;
    ev.amount = amount;

    MarsCore::invokeEvent<Event::IncProduction>(ev);
}


void decProduction(int p, int target, Resources restype, int amount) {
    int &t = player[p].production[static_cast<int>(restype)];
    amount = min(amount, t);
    t -= amount;

    ResourcesEvent ev;
    ev.player = p;
    ev.target = target;
    ev.restype = restype;
    ev.amount = amount;

    MarsCore::invokeEvent<Event::DecProduction>(ev);
}

bool doAction(int) {
	return false;
}

void placeGreenery(int p) {

}

void placeOcean(int p) {

}

void placeCity(int p) {

}

void incTemperature(int p) {

}
