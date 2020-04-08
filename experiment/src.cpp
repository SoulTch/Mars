#include <nlohmann/json.hpp>
#include <iostream>

using json = nlohmann::json;
using namespace std;

int main(void) {
    json a = {
        {"key1", 123},
        {"hello", "wow"}
    };

    cout << a << endl;   
}