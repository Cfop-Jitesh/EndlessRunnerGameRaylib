//Libraries
#include <raylib.h>
#include <stdio.h>
#include "../include/gameMechanics.h"
#include "../include/animations.h"
#include "../include/renderTerrain.h"

//Main Function
int main(){
    bool started = true;
    const int screenWidth = 800;  // Screen width
    const int screenHeight = 600; // Screen height
    int currentRunningFrame = 1;
    Player player ={
        .isJumping = false,
        .isRunning = false,
        .isStanding = true,
        .position = {0, 450},
        .vel = 2.5
    };
    int runningFrameCount = 0;
    // Initialize the window
    InitWindow(screenWidth, screenHeight, "Runner");


    //Textures
    Texture2D IdleMan = LoadTexture("assets/idle.png");
    Texture2D runningSpriteSheet = LoadTexture("assets/Run.PNG");

    // Set the target FPS (frames per second)
    SetTargetFPS(60);
    while(!started){  //Loop for main menu
        ;
    }
    while(started && !WindowShouldClose()){ //Loop for actual game
        if(player.isRunning){
            runningFrameCount+=1;
            UpdateFrame(&runningFrameCount, &currentRunningFrame);
            DrawSprite(runningSpriteSheet, currentRunningFrame, player);
        }
        else if(!player.isRunning){
            DrawIdleMan(IdleMan, player);
        }
        changePlayerState(&player, runningFrameCount, currentRunningFrame);
        printf("CurrentFrame: %d\n", currentRunningFrame);
        printf("Frame: %d\n", runningFrameCount);
        PlayerMovement(&player);
        BeginDrawing();
        ClearBackground(RAYWHITE);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}