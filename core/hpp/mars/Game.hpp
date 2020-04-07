#pragma once

#include <vector>
#include <list>
#include <functional>

#include <core/hpp/model/Player.hpp>
#include <core/hpp/model/Card.hpp>
#include <core/hpp/model/BoardTile.hpp>
#include <core/hpp/model/Surface.hpp>
#include <core/hpp/mars/EventHandler.hpp>

#define MAX_PLAYER 5

using namespace std;
using namespace MarsCore;

extern int numOfPlayers;
extern int generation;

extern MarsCore::Player player[MAX_PLAYER];
extern map<string, MarsCore::CardArche> cardPool;
extern map<string, MarsCore::CorpArche> corpPool;
extern vector<MarsCore::Project *> projectDeck;
extern vector<MarsCore::Project *> discardedDeck;

extern Surface surface;
extern Board board;

void reload();

