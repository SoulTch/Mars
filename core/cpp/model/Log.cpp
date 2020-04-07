#include <core/hpp/model/Log.hpp>

#include <string>

namespace MarsCore {
    void Log::add(Log *k) {
        log.push_back(k);
    }

    Log::~Log() {
        for (auto x : log) delete x;
    }
}