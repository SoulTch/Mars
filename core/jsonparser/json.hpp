#pragma once

#include <map>
#include <vector>
#include <string>

namespace Json {
    class json {
    public:
        std::vector<json> arr;
        int val;
        std::string str;
        std::map<std::string, json> obj;

        json();
        json operator[](std::string key);
        json operator[](const char *key);
        json operator[](int key);
        operator int();
        operator std::string();
    };
    json parse(std::string s);
}