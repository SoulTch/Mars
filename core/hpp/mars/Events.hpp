#pragma once

// Game generation events
void startGame();
void finishGame();

void generationBegin();
bool generationEnd();

bool doAction(int); 
void actionDone(int);

void turnBegin(int);
void turnEnd(int, bool); 



// Card Events
void drawCard();
void addCard();
void removeCard();
void playCard();