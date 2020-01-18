#include <iostream>
#include <type_traits>
#include <set>
#include <vector>
#include <span>

using namespace std;

namespace detail {
    template<typename...> struct _Tuple;

    template<typename T, typename... V>
    struct _Tuple<T, V...> : public _Tuple<V...> {
        T val;
        template<unsigned idx> auto get() {
            return (_Tuple<V...>::template get<idx-1>());
        }
        template<> T &get<0>() {
            return val;
        }
    };

    template<typename T>
    struct _Tuple<T> {
        T val;
        template<unsigned idx> T& get() = delete;
        template<> T &get<0>() {
            return val;
        }
    };
}

template<typename... V>
class Tuple {
    detail::_Tuple<V...> v;
};

template<unsigned idx, typename... V>
auto Get(Tuple<V...> &t) {
    return (t.template get<idx>());
}

int main(void) {
    Tuple<int, double, vector<int>> t;
}