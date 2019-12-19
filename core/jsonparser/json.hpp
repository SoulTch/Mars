#pragma once

#include <map>
#include <vector>
#include <string>
#include <variant>

using namespace std;

namespace Json {
    class json {
    public:
        json();
        static json parse(const string s);

        json &operator[](const string key);
        json &operator[](const char *const key);
        json &operator[](const int key);
        operator int();
        operator string();
        variant<monostate, vector<json>, int, string, map<string, json>> content;
    };
}