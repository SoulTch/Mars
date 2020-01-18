#pragma once

/*
 * server -> client
 * ask command
 * notice
 *
 * client -> server
 * command
 * request
 */

#include <vector>

#include <core/hpp/model/Card.hpp>
#include <core/hpp/model/BoardTile.hpp>
#include <core/hpp/model/Ability.hpp>
#include <core/hpp/model/Surface.hpp>
#include <core/hpp/model/Payment.hpp>

using namespace std;
using namespace MarsCore;

Ability *chooseAbility(int, vector<Ability *> &);

vector<Card *> chooseHandCommand(int, int);

vector<Payment *> choosePaymendCommand(int, vector<Payment *> &);
vector<Card *> chooseHandCommand(int, int, int, vector<Card *> &);
vector<Entity *> chooseEntityCommand(int, vector<Entity *> &);
vector<Tile *>   chooseTileCommand(int, int, int, vector<Tile *> &);
vector<Card *> chooseCardCommand(int, int, int, vector<Card *> &);
vector<Card *> purchaseCommand(int, vector<Card *> &);

int chooseTaskCommand(int);
int chooseSurfaceTaskCommand(int);
int choosePlayerCommand(int);

int removeResourcesCommand(int, int, int); // player, max, target
int removeResourcesCounterCommand(int, int, Entity *);


