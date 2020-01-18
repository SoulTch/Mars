#pragma once

#include <core/hpp/model/Entity.hpp>

using namespace std;
using namespace MarsCore;

class BasicProject : public Entity {
public:
    BasicProject(int, int);

    virtual bool available();
    virtual void play() = 0;
};

class SellPatentProject : public BasicProject {
public:
    SellPatentProject(int);
    bool available() override;
    void play() override;
};

class PowerPlantProject : public BasicProject {
public:
    PowerPlantProject(int);
    void play() override;
};

class AsteroidProject : public BasicProject {
public:
    AsteroidProject(int);
    bool available() override;
    void play() override;
};

class AquiferProject : public BasicProject {
public:
    AquiferProject(int);
    bool available() override;
    void play() override;
};

class GreeneryProject : public BasicProject {
public:
    GreeneryProject(int);
    bool available() override;
    void play() override;
};

class CityProject : public BasicProject {
public:
    CityProject(int);
    bool available() override;
    void play() override;
};


