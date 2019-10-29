#include "json.hpp"

using namespace Json;

json::json() {
    val = 0;
}

json json::operator[] (std::string key) {
    return obj[key];
}

json json::operator[] (const char *key) {
    return obj[std::string(key)];
}

json json::operator[] (int key) {
    return arr[key];
}

json::operator int() {
    return val;
}

json::operator std::string() {
    return str;
}

std::string str;
int idx;

void norm() {
    while(idx < str.size() and (str[idx] == ' ' or str[idx] == '\n' or str[idx] == '\t')) idx++;
}

char next() {
    norm();
    if (idx >= str.size()) return 0;
    return str[idx];
}

char require() {
    norm();
    if (idx >= str.size()) return 0;
    return str[idx++];
}

void require(char c) {
    assert(require() == c);
}

json parse() {
    char c = next();
    json ret;
    if (c == '{') {
        require('{');
        while(true) {
            std::string key = parse();
            require(':');
            json val = parse();
            ret.obj[key] = val;

            if (next() == ',') require(',');
            else break;
        }
        require('}');
    } else if (c == '[') {
        require('[');
        while(true) {
            ret.arr.push_back(parse());
            if (next() == ',') require(',');
            else break;
        }
        require(']');
    } else if (c == '\"') {
        require('\"');
        while(next() != '\"') ret.str += require();
        require('\"');
    } else if ('0' <= c and c <= '9') {
        ret.val = 0;
        while('0' <= next() and next() <= '9') {
            ret.val = 10*ret.val+require()-'0';
        }
    } else {
        assert(false);
    }
    return ret;
}

json Json::parse(std::string s) {
    str = s;
    idx = 0;
    return ::parse();
}