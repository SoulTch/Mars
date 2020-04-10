

#pragma once

#include <vector>
#include <list>
#include <functional>

#include <core/hpp/model/Player.hpp>
#include <core/hpp/model/Card.hpp>
#include <core/hpp/mars/Game.hpp>
#include <core/hpp/model/BoardTile.hpp>
#include <core/hpp/mars/EventHandler.hpp>

// turn actions
void startGame();
void finishGame();

void generationBegin();
bool generationEnd();

bool doAction(int); 
void actionDone(int);

void turnBegin(int);
void turnEnd(int, bool); 

// Action functions
vector<Project *> seekCard(int amount);
void addCard(int player, const vector<Project *> &);

vector<Project *> selectCard();
void removeCard(int player, const vector<Project *> &);

void incTerraformingRating(int player);

void placeGreenery(int player);
void placeOcean(int player);
void placeCity(int player);
void incTemperature(int player);

void addResources(int player, Resources restype, int amount);
void addResources(int player, int target, Resources restype, int amunt);
void subResources(int player, Resources restype, int amount);
void subResources(int player, int target, Resources restype, int amunt);
void incProduction(int player, Resources restype, int amount);
void incProduction(int player, int target, Resources restype, int amunt);
void decProduction(int player, Resources restype, int amount);
void decProduction(int player, int target, Resources restype, int amunt);

