//Libraries
#include <raylib.h>
#include <stdlib.h>
#include "../include/gameMechanics.h"
#include "../include/animations.h"
#include "../include/renderTerrain.h"

//Main Function
int main(){
    bool started = true;
    const int screenWidth = 800;  // Screen width
    const int screenHeight = 600; // Screen height
    Player player ={
        .isJumping = false,
        .isRunning = false,
        .isStanding = true,
        .position = {0, 450},
        .vel = 2.5
    };
    // Initialize the window
    InitWindow(screenWidth, screenHeight, "Runner");


    //Textures
    Texture2D IdleMan = LoadTexture("assets/idle.png");

    // Set the target FPS (frames per second)
    SetTargetFPS(60);
    while(!started){  //Loop for main menu
        ;
    }
    while(started && !WindowShouldClose()){ //Loop for actual game
        changePlayerState(&player);
        PlayerMovement(&player);
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawIdleMan(IdleMan, player);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}