#pragma once

#include <vector>
#include <list>
#include <functional>

#include <core/hpp/model/Player.hpp>
#include <core/hpp/model/Card.hpp>
#include <core/hpp/model/BoardTile.hpp>
#include <core/hpp/mars/EventHandler.hpp>

#define MAX_PLAYER 5

using namespace std;

extern int numOfPlayers;
extern int generation;

extern MarsCore::Player player[MAX_PLAYER];
extern map<string, MarsCore::CardArche> cardPool;
extern map<string, MarsCore::CorpArche> corpPool;
extern vector<MarsCore::Card *> projectDeck;
extern vector<MarsCore::Card *> discardedDeck;

extern Surface surface;
extern Board board;

// interface functions

// turn actions
void startGame();
void finishGame();

void generationBegin();
bool generationEnd();

bool doAction(int); 
void actionDone(int);

void turnBegin(int);
void turnEnd(int, bool); 

// Task Actions
vector<Card *> seekCard(int);
void addCard(int player, vector<Card *> &&, bool isDraw = false);

void chgProduction(int player, Resources res, int amount);
void chgResources (int player, Resources res, int amount);
void incSurface(int player, Indicator ind);
void incTerraforming(int player, int amount);
