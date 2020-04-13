#include <functional>

#include <core/hpp/model/Entity.hpp>
#include <core/hpp/model/Enchantment.hpp>

#include <core/hpp/mars/CardLoader.hpp>
#include <core/hpp/mars/EventHandler.hpp>
#include <core/hpp/mars/Events.hpp>
#include <core/hpp/mars/Interface.hpp>

using namespace std;
using namespace MarsCore;

map<string, Power<Corporation>> loadCorporationPower() {
    map<string, Power<Corporation>> m;

    Power<Corporation> power;

    power.clear();
    power.addEffect([](Corporation *p, json &log) {
        auto ev = [=](const PlayProjectEvent &ev) {
            Project *pr = ev.card;
            if (pr->arche->cost >= 20) {
                addResources(p->owner, p->owner, Resources::Megacredit, 4);
            }
            return true;
        };
        addPrivateEventListener<Event::PlayCard, PlayProjectEvent>(p->owner, ev);
    });
    m.emplace("cor-001", power);

    power.clear();
    power.addEffect([](Corporation *p, json &log) {
        player[p->owner].properties.regrowth.enableEnchant(
			setEnchant<Enchantable<int>>("Regrowth", 7)
		);
    });
    m.emplace("cor-002", power);

    power.clear();
    

    return m;
}