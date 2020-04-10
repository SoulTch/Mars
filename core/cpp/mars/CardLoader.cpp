#include <fstream>
#include <nlohmann/json.hpp>

#include <core/hpp/mars/CardLoader.hpp>


using namespace std;
using namespace MarsCore;
using json = nlohmann::json;


json loadJson(const string &filename) {
    ifstream in(filename);
    assert(in);

    in.seekg(0, ios::end);
    size_t len = in.tellg();
    in.seekg(0);

    string contents(0, len);
    in.read(&contents[0], len);

    return json::parse(contents);
}



map<string, CorpArche> LoadCorporation(string filename) {
    json corp = loadJson(filename);

    map<string, CorpArche> ret;
    auto effect = loadCorporationPower();

    for (auto &[id, content] : corp["cardlist"].items()) {
       	ret.emplace(id, CorpArche(id, content, effect[id]));
    }

    return ret;
}

map<string, CardArche> LoadProject(string filename) {
    json proj = loadJson(filename);

    map<string, CardArche> ret;
	auto effect = loadProjectPower();

    for (auto &[id, content]: proj["cardlist"].items()) {
		ret.emplace(id, ProjectArche(id, content, effect[id]));
    }

    return ret;
}