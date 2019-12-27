#include <core/hpp/mars/BasicProject.hpp>
#include <core/hpp/model/Surface.hpp>
#include <core/hpp/mars/Game.hpp>

using namespace std;
using namespace MarsCore;

bool BasicProject::available() {
    return player[pid].payable(price);
}

bool SellPatentProject::available() {
    return player[pid].has_hand();
}

void SellPatentProject::play() {

}

bool AsteroidProject::available() {
    return player[pid].payable(price) and surface.improvable<Indicator::Temperature>();
}

bool AquiferProject::available() {
    return player[pid].payable(price) and surface.improvable<Indicator::Ocean>();
}

bool GreeneryProject::available() {
    return player[pid].payable(price) and board.placeable();
}

bool CityProject::available() {
    return player[pid].payable(price) and board.city_placeable();
}

