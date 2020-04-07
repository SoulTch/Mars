#pragma once

struct SimpleEvent {
    int player;
};

struct CardEvent {
    int player;
    vector<Project *> const *cards;
};

struct PlayCardEvent {
    int player;
    bool isCorp;
    Card * card;
};

struct ResourcesEvent {
    int player;
    int target;
    Resources restype;
    int amount;
};