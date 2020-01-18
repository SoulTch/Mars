#pragma once

#include <string>
#include <map>

#include <core/hpp/model/Card.hpp>
#include <core/hpp/model/Entity.hpp>
#include <core/hpp/model/Surface.hpp>
#include <core/hpp/model/Resources.hpp>
#include <core/hpp/model/Tasks.hpp>

using namespace std;
using namespace MarsCore;

map<string, CorpArche> loadCorporation(string);
map<string, CardArche> loadProject(string);

map<string, Power> loadCorporationPower();
map<string, Power> loadProjectPower();
map<string, Power> loadActionPower();

