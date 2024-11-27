#include <raylib.h>
#include "../include/gameMechanics.h"
#include "../include/animations.h"
#include "../include/renderTerrain.h"

void changePlayerState(Player* player, int runningFrameCount, int currentRunningFrame){
    if(IsKeyDown(KEY_RIGHT)){
        player->isRunning = true;
        player->isStanding = false;
        
    }
    if(IsKeyDown(KEY_SPACE)){
        player->isJumping = true;
    }
}

void PlayerMovement(Player* player){
    if(player->isRunning){
        player->position.x += player->vel;
    }
}
