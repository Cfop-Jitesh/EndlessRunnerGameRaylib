#include <raylib.h>
#include "../include/gameMechanics.h"
#include "../include/animations.h"
#include "../include/renderTerrain.h"
#include <stdlib.h>
#include <time.h>

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

int chooseOne(int num1, int num2, int num3) {
    // Array of numbers
    int numbers[3] = {num1, num2, num3};
    
    // Generate a random index between 0 and 2
    int randomIndex = rand() % 3;
    
    // Return the selected number
    return numbers[randomIndex];
}

void summoningBox(box* boxes[]) {
    for (int i = 0; i < TOTAL_BOX; i++) {
        if (boxes[i] == NULL) {  // Only allocate if not already allocated
            boxes[i] = (box*)malloc(sizeof(box));  // Allocate memory for each box
            if (boxes[i] == NULL) {
                exit(1);
            }

            // Initialize position and size
            boxes[i]->position.x = (i > 0) ? boxes[i - 1]->position.x + chooseOne(50, 75, 120) : 550;
            boxes[i]->position.y = 450;
            boxes[i]->size = (Vector2){chooseOne(50, 30, 45), 50};
            boxes[i]->inFront = true;
        }
    }
}
