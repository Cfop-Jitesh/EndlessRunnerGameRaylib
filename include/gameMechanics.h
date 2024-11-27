#ifndef GAMEMECHANICS_H
#define GAMEMECHANICS_H

#include "raylib.h"

// Define a structure for player mechanics
typedef struct Player{
    Vector2 position;
    float vel;      // Player's velocity
    bool isJumping;
    bool isRunning;
    bool isStanding;
}Player;


typedef struct box{
    Vector2 position;
    Vector2 size;
    bool inFront;
}box;

#define TOTAL_BOX 4

//Functions
void changePlayerState(Player* player, int runningFrameCount, int currentRunningFrame);
void PlayerMovement(Player* player);
void summoningBox(box* boxes[]);
int chooseOne(int num1, int num2, int num3);
#endif
