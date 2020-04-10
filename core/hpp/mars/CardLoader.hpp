#pragma once

#include <string>
#include <map>

#include <core/hpp/model/Card.hpp>
#include <core/hpp/model/Entity.hpp>
#include <core/hpp/model/Surface.hpp>
#include <core/hpp/model/Resources.hpp>
#include <core/hpp/model/Tasks.hpp>

std::map<std::string, MarsCore::CorpArche> loadCorporation(std::string filename);
std::map<std::string, MarsCore::CardArche> loadProject(std::string filename);

std::map<std::string, MarsCore::Power<MarsCore::Corporation>> loadCorporationPower();
std::map<std::string, MarsCore::Power<MarsCore::Project>> loadProjectPower();
std::map<std::string, MarsCore::Power<MarsCore::PermanentAbility>> loadActionPower();

