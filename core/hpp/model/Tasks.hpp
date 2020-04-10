#pragma once

#include <vector>
#include <optional>
#include <functional>

#include <core/hpp/model/Log.hpp>

namespace MarsCore {

template<typename T>
class Task {
public:
    std::optional<std::function<bool(T *)>> available;
    std::optional<std::function<void(T *, Log *)>> play;
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

    void addEffect(const std::function<void(T *, Log *)> &v) {
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

    void run(T *v, Log *l) {
        for (auto &x : _play) {
            x(v, l);
        }
    }
private:
    std::vector<std::function<bool(T *)>> _available;
    std::vector<std::function<void(T *, Log *)>> _play;
};

}

// invokable? -> Acts
// stackable? -> Card
// enchantable? -> Entity