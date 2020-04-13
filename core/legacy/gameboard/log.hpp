#pragma once

#include <vector>
#include <string>

class Log {
public:
    virtual std::string to_string();
    void append(json &p);
    
private:
    std::vector<json &> logs;
};

class DrawCardLog;
