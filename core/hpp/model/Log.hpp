#pragma once

#include <vector>

namespace MarsCore {
class Log {
public:
    void add(Log *l);
    ~Log();

    std::vector<Log *> log;
};

}