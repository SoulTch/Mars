#pragma once

struct StartGameEvent {
    int player;
};

struct FinishGameEvent {
    int player;
};

struct GenerationBeginEvent {
    int player;
};

struct GenerationEndEvent {
    int player;
};

struct ActionDoneEvent {
    int player;
};

struct TurnBeginEvent {
    int player;
};

struct TurnEndEvent {
    int player;
};


