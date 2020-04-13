#pragma once

#include <vector>
#include <optional>
#include <functional>

#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace MarsCore {

template<typename T>
class Task {
public:
    std::optional<std::function<bool(T *)>> available;
    std::optional<std::function<void(T *, json &)>> play;
};

template<typename T>
class Power {
public:
    void addTask(const Task<T> &v) {
        if (v.available) addCondition(*(v.available));
        if (v.play) addEffect(*(v.play));
    }

    void addCondition(const std::function<bool(T *)> &v) {
        _available.push_back(v);
    }

    void addEffect(const std::function<void(T *, json &)> &v) {
        _play.push_back(v);
    }

    void clear() {
        _available.clear();
        _play.clear();
    }

    bool available(T *v) {
        for (auto &x : _available) {
            if (!x(v)) return false;
        }
        return true;
    }

    void run(T *v, json &l) {
        for (auto &x : _play) {
            x(v, l);
        }
    }
private:
    std::vector<std::function<bool(T *)>> _available;
    std::vector<std::function<void(T *, json &)>> _play;
};

}

// invokable? -> Acts
// stackable? -> Card
// enchantable? -> Entity