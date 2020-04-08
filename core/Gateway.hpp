#pragma once

#include <string>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace Gateway {

void initGateway();
    
// server -> client
json command(int player, const json &content);
void command(int size, int *player, json *req, json *res);
void notify(int player, const json &msg);

// client -> server



}