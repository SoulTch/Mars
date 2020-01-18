#include <core/hpp/mars/BasicProject.hpp>
#include <core/hpp/model/Surface.hpp>
#include <core/hpp/mars/Game.hpp>

using namespace std;
using namespace MarsCore;

BasicProject::BasicProject(int pid, int cost) : pid(pid), cost(cost) { }

bool BasicProject::available() {
    return player[pid].payable(cost);
}

SellPatentProject::SellPatentProject(int pid) : BasicProject(pid, 1) { }

bool SellPatentProject::available() {
    return player[pid].has_hand();
}

void SellPatentProject::play() {
    auto tosell = player[pid].selectCard();
    player[pid].removeCard(tosell);
    player[pid].addResources(Resources::Megacredit, tosell.size()*cost);
}

PowerPlantProject::PowerPlantProject(int pid) : BasicProject(pid, 11) { }

void PowerPlantProject::play() {
    player[pid].subResources(Resources::Megacredit, cost);
    player[pid].incProduction(Resources::Electricity, 1);
}

AsteroidProject::AsteroidProject(int pid) : BasicProject(pid, 11) { }


bool AsteroidProject::available() {
    return player[pid].payable(cost) and surface.improvable(Indicator::Temperature);
}


void AsteroidProject::play() {
    player[pid].subResources(Resources::Megacredit, cost);
    player[pid].incTerraformingRating();
}

AquiferProject::AquiferProject(int pid) : BasicProject(pid, 18) { }

bool AquiferProject::available() {
    return player[pid].payable(cost) and surface.improvable(Indicator::Ocean);
}

void AquiferProject::play() {
    player[pid].subResources(Resources::Megacredit, cost);
    player[pid].placeOcean();
}

GreeneryProject::GreeneryProject(int pid) : BasicProject(pid, 23) { }

bool GreeneryProject::available() {
    return player[pid].payable(cost) and board.placeable();
}

void GreeneryProject::play() {
    player[pid].subResources(Resources::Megacredit, cost);
    player[pid].placeGreenery();
}

CityProject::CityProject(int pid) : BasicProject(pid, 25) { }

bool CityProject::available() {
    return player[pid].payable(cost) and board.city_placeable();
}

void CityProject::play() {
    player[pid].subResources(Resources::Megacredit, cost);
    player[pid].placeCity();
    player[pid].incProduction(Resources::Megacredit, 1);
}

