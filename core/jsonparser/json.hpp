#pragma once

#include <map>
#include <vector>
#include <string>
#include <variant>

using namespace std;

namespace Json {
    class json {
    public:
        json(int);
        json(string);
        json(json);

        json &operator[](const string &key);
        json &operator[](const int key);
        operator int();
        operator string();
        string toJsonString() const;

        variant<monostate, vector<json>, int, string, map<string, json>> content;
    };
    
    json parse(const string &s);
}