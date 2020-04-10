#include <nlohmann/json.hpp>
#include <iostream>
#include <thread>

using json = nlohmann::json;
using namespace std;

struct A {

};

extern A *tmp[5];
A *tmp[5];

int main(void) {
	cout << sizeof(tmp) << endl;
}