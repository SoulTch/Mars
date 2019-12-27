#pragma once

#include <core/hpp/model/Entity.hpp>

using namespace std;
using namespace MarsCore;

class BasicProject : public Entity {
public:
    int price, pid;
    BasicProject(int pid) : pid(pid) { }

    virtual bool available();
    virtual void play() = 0;
};

class SellPatentProject : public BasicProject {
public:
    SellPatentProject(int pid) : BasicProject(pid) { 
        price = 1;
    }

    bool available() override;
    void play() override;
};

class PowerPlantProject : public BasicProject {
public:
    PowerPlantProject() : BasicProject(pid) { 
        price = 11;
    }
    void play() override;
};

class AsteroidProject : public BasicProject {
public:
    AsteroidProject() : BasicProject(pid) { 
        price = 14;
    }
    bool available() override;
    void play() override;
};

class AquiferProject : public BasicProject {
public:
    AquiferProject() : BasicProject(pid) { 
        price = 18;
    }

    bool available() override;
    void play() override;
};

class GreeneryProject : public BasicProject {
public:
    GreeneryProject() : BasicProject(pid) { 
        price = 23;
    }

    bool available() override;
    void play() override;
};

class CityProject : public BasicProject {
public:
    CityProject() : BasicProject(pid) { 
        price = 25;
    }

    bool available() override;
    void play() override;
};


