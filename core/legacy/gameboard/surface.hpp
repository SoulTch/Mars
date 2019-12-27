#pragma once

class Indicator {
public:
    virtual void increase(Game *game);
    virtual bool satisfied(Game *game);
};

class OxygenIndicator : public Indicator {
public:
    OxygenIndicator();
    void increase(Game *game) override;
    bool satisfied(Game *game) override;
private:
    int value;
};

class SeaIndicator : public Indicator {
public:
    SeaIndicator();
    void increase(Game *game) override;
    bool satisfied(Game *game) override;
private:
    int value;
};

class TemperatureIndicator : public Indicator {
public:
    TemperatureIndicator();
    void increase(Game *game) override;
    bool satisfied(Game *game) override;
};

class VenusIndicator : public Indicator {
public:
    VenusIndicator();
    void increase(Game *game) override;
    bool satisfied(Game *game) override;
private:
    int value;
};