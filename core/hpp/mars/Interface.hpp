

#pragma once

#include <vector>
#include <list>
#include <functional>

#include <nlohmann/json.hpp>

#include <core/hpp/model/Player.hpp>
#include <core/hpp/model/Card.hpp>
#include <core/hpp/mars/Game.hpp>
#include <core/hpp/model/BoardTile.hpp>
#include <core/hpp/mars/EventHandler.hpp>

using json = nlohmann::json;

// turn actions
void initComplete();
void setCorporation(int player, Corporation *corp);
void startGame();
void finishGame();

void generationBegin();
void generationEnd();

bool doAction(int); 
void actionDone(int);

void turnBegin(int);
void turnEnd(int, bool); 

// Action functions
void drawCard(json *, int player, int amount);
void addCard(json *, int player, const vector<Project *> &);
void removeCard(json *, int player, const vector<Project *> &);

void incTerraformingRating(json *, int player);

void placeGreenery(json *, int player);
void placeOcean(json *, int player);
void placeCity(json *, int player);
void incTemperature(json *, int player);

void addResources(json *, int player, Resources restype, int amount);
void addResources(json *, int player, int target, Resources restype, int amunt);
void incProduction(json *, int player, Resources restype, int amount);
void incProduction(json *, int player, int target, Resources restype, int amunt);

void reload();
Project *seekCard();

// async request functions
vector<Corporation *> selectStartup(const vector<array<Corporation *, 2>>& corps, const vector<vector<Project *>> &prjs);
void shopCardAsync(const vector<vector<Project *>> &prjs);


// request functions
