#pragma once

#include <string>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace Gateway {

void initGateway();
    
// server -> client
json command(int player, const json &content);
std::vector<json> command(const std::vector<std::pair<int, json>> &content);
void notify(int player, const json &msg);

// client -> server



}