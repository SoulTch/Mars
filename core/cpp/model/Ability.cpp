#include <core/hpp/model/Ability.hpp>

using namespace MarsCore;

bool Activatable::available() {
    return is_avail;
}

void Activatable::set_validity(bool flag) {
    is_avail = flag;
}

void AbilityGroup::refresh(int n_era) {
    if (era == n_era) return;
    era = n_era;

    for (auto &x : *this) {
        x->revalidate();
    }
}

InstantAbility::InstantAbility(decltype(_reval) _reval, decltype(_run) _run) : _reval(_reval), _run(_run) {

}

void InstantAbility::revalidate() {
    set_validity(_reval(owner));
}

void InstantAbility::run(Log *l) {
    _run(owner, l);
}
