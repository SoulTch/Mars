#pragma once

#include <vector>
#include <string>

class Log {
public:
    virtual std::string to_string();
    void append(Log *p);
    
private:
    std::vector<Log *> logs;
};

class DrawCardLog;
