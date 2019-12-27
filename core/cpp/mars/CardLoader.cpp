#include <fstream>

#include <core/hpp/mars/CardLoader.hpp>

#include <core/jsonparser/json.hpp>

using namespace std;


Json::json loadJson(const string &filename) {
    ifstream in(filename);
    assert(in);

    in.seekg(0, ios::end);
    size_t len = in.tellg();
    in.seekg(0);

    string contents(0, len);
    in.read(&contents[0], len);

    return Json::json::parse(contents);
}



map<string, MarsCore::CorpArche> LoadCorporation(string filename) {
    Json::json corp = loadJson(filename);

    auto &x = get<map<string, Json::json>>(corp.content);
    map<string, MarsCore::CorpArche> ret;
    auto effect = loadCorporationPower();

    for (auto [id, content] : x) {
        ret[id] = MarsCore::CorpArche();
    }

    return ret;
}

map<string, MarsCore::CardArche> LoadProject(string filename) {
    Json::json proj = loadJson(filename);

    auto &x = get<map<string, Json::json>>(proj.content);
    map<string, MarsCore::CardArche> ret;

    for (auto [id, content]: x) {
        ret[id] = MarsCore::CardArche();

    }

    return ret;
}