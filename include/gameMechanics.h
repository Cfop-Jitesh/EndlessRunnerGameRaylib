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


//Functions
void changePlayerState(Player* player, int runningFrameCount, int currentRunningFrame);
void PlayerMovement(Player* player);
#endif
