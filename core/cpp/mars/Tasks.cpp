
#include <core/hpp/model/Tasks.hpp>

namespace MarsCore {

bool Activatable::available() {
    return is_avail;
}

void Activatable::set_validity(bool flag) {
    is_avail = flag;
}