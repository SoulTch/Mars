#pragma once

#include <vector>
#include <list>
#include <functional>

#include <core/hpp/model/Player.hpp>
#include <core/hpp/model/Card.hpp>
#include <core/hpp/mars/EventHandler.hpp>

#define MAX_PLAYER 5

using namespace std;

extern int numOfPlayers;
extern int generation;

extern MarsCore::Player player[MAX_PLAYER];
extern map<string, MarsCore::CardArche> cardPool;
extern vector<MarsCore::Card *> projectDeck;
extern vector<MarsCore::Card *> discardedDeck;

extern Surface surface;