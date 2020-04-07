#include <core/hpp/model/Card.hpp>
#include <core/hpp/model/Ability.hpp>

namespace MarsCore {
    void Corporation::revalidate() {
        set_validity(true);
    }

    void Corporation::run(Log *l) {
        base.run(this, l);
        power.run(this, l);
    }

    void Project::revalidate() {
        set_validity(base.available(this) and power.available(this));
    }

    void Project::run(Log *l) {
        base.run(this, l);
        power.run(this, l);
    }
}