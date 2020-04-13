#include <nlohmann/json.hpp>
#include <iostream>
#include <thread>

using json = nlohmann::json;
using namespace std;

int main(void) {
	cout << string(7, 'a') << endl;
}