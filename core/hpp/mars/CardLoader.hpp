#pragma once

#include <string>
#include <map>

#include <core/hpp/model/Card.hpp>
#include <core/hpp/model/Entity.hpp>

using namespace std;
using namespace MarsCore;

map<string, CorpArche> LoadCorporation(string);
map<string, CardArche> LoadProject(string);

map<string, Power<Corporation *>> loadCorporationPower();
map<string, Power<Project *>> loadProjectPower();