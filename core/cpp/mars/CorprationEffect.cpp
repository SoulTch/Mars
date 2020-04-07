#pragma once

#include <functional>

#include <core/hpp/mars/CardLoader.hpp>
#include <core/hpp/model/Entity.hpp>
#include <core/hpp/mars/EventHandler.hpp>
#include <core/hpp/mars/Events.hpp>
#include <core/hpp/mars/Interface.hpp>

using namespace std;
using namespace MarsCore;

using ACT = const Activate<Corporation> &;

map<string, Power<Corporation>> loadCorporationPower() {
    map<string, Power<Corporation>> m;

    Power<Corporation> power;
    Power<Entity> ____p;

    power.clear();
    power.addEffect([](ACT p) {
        auto ev = [=](PlayCardEvent &ev) {
            Project *pr = static_cast<Project *>(ev.card);
            if (pr->form.cost >= 20) {
                addResources(p.invoker, p.invoker, Resources::Megacredit, 4);
            }
            return true;
        };
        addPrivateEventListener<Event::PlayCard, PlayCardEvent>(p.invoker, ev);
    });
    m.emplace("cor-001", power);

    power.clear();
    power.addEffect([](ACT p) {
        player[p.invoker].properties.regrowthGreenery = 7;
    });
    m.emplace("cor-002", power);

    power.clear();
    

    return m;
}