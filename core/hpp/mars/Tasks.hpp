#pragma once

#include <string>
#include <map>

#include <core/hpp/model/Card.hpp>
#include <core/hpp/model/Entity.hpp>
#include <core/hpp/model/Surface.hpp>
#include <core/hpp/model/Resources.hpp>
#include <core/hpp/model/Tasks.hpp>

using namespace std;
using namespace MarsCore;

// Project Task


template<typename V, typename T>
V getv(T &v) {
    if constexpr (is_same_v<V, T>) {
        return v;
    } else {
        return v();
    }
}

template<typename A, typename T> 
Task<A> drawCardTask(const T &amount) {
    return {
        nullopt,
        [=](A *act) {
			
        }
    };
}