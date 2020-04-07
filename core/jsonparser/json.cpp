#include "json.hpp"
#include <sstream>

using namespace Json;
using namespace std;

json &json::operator[] (const string key) {
    return get<map<string, json>>(content)[key];
}

json &json::operator[] (const int key) {
    return get<vector<json>>(content)[key];
}

json::operator int() {
    return get<int>(content);
}

json::operator string() {
    return get<string>(content);
}

string json::toJsonString() const {
    return visit([](const auto &x) -> string {
        using Type = decay_t<decltype(x)>;
        ostringstream ret;
        if constexpr(is_same_v<Type, string>) {
            ret << '\"' << x << '\"';
        } else if constexpr(is_same_v<Type, int>) {
            ret << x;
        } else if constexpr(is_same_v<Type, vector<json>>) {
            ret << '[';
            bool fst = true;
            for (const json &t : x) {
                ret << t.toJsonString() << (fst?"":",");
                fst = false;
            }
            ret << ']';
        } else if constexpr(is_same_v<Type, map<string, json>>) {
            ret << '{';
            bool fst = true;
            for (const auto& [key, val] : x) {
                ret << key << ':' << val.toJsonString() << (fst?"":",");
                fst = false;
            }
            ret << '}';
        } else {
            assert(false);
        }

        return ret.str();
    }, content);
};

static string str;
static int idx;

static void norm() { 
    while(idx < str.size() and (str[idx] == ' ' or str[idx] == '\n' or str[idx] == '\t')) idx++;
}

static char next() {
    norm();
    if (idx >= str.size()) return 0;
    return str[idx];
}

static char require() {
    norm();
    if (idx >= str.size()) return 0;
    return str[idx++];
}

static void require(char c) {
    assert(require() == c);
}

json parse() {
    char c = next();
    json ret;
    if (c == '{') {
        ret.content = map<string, json>();
        auto &ref = get<map<string, json>>(ret.content);

        require('{');
        while(true) {
            string key = parse();
            require(':');
            json val = parse();
            ref[key] = val;

            if (next() == ',') require(',');
            else break;
        }
        require('}');
    } else if (c == '[') {
        ret.content = vector<json>();
        auto &ref = get<vector<json>>(ret.content);

        require('[');
        while(true) {
            ref.push_back(parse());
            if (next() == ',') require(',');
            else break;
        }
        require(']');
    } else if (c == '\"') {
        ret.content = "";
        auto &ref = get<string>(ret.content);

        require('\"');
        while(next() != '\"') ref += require();
        require('\"');
    } else if ('0' <= c and c <= '9') {
        ret.content = 0;
        auto &ref = get<int>(ret.content);

        while('0' <= next() and next() <= '9') {
            ref = 10*ref+require()-'0';
        }
    } else {
        assert(false);
    }
    return ret;
}

json json::parse(const string s) {
    str = s;
    idx = 0;
    return ::parse();
}