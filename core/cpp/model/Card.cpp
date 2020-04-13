#include <core/hpp/model/Card.hpp>
#include <core/hpp/model/Ability.hpp>

using namespace MarsCore;
using namespace std;

CorpArche::CorpArche(const std::string &id, const json& arc, Power<Corporation> power) {

}

Corporation::Corporation() { }
Corporation::Corporation(CorpArche *arche) : arche(arche) { }

void Corporation::run() {
    arche->base.run(this, nullptr);
    arche->power.run(this, nullptr);
}

Project::Project() { }
Project::Project(ProjectArche *arche) : arche(arche) { }

ProjectArche::ProjectArche(const std::string &id, const json &arc, Power<Project> power) {
	
}

void Project::revalidate() {
    set_validity(arche->base.available(this) and arche->power.available(this));
}

void Project::run(json &l) {
    arche->base.run(this, l);
    arche->power.run(this, l);
}

