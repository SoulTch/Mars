#include <string>
#include <sstream>
#include <random>

namespace Gateway {

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<int> distribution(0, 1e9);

void unicommand(std::string req) {
    std::ostringstream os;

    os << "{" << ""
}

}