//Libraries
#include <raylib.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
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
    box* boxes[TOTAL_BOX] = {NULL};

    int runningFrameCount = 0;
    // Initialize the window
    InitWindow(screenWidth, screenHeight, "Runner");


    //Textures
    Texture2D IdleMan = LoadTexture("assets/idle.png");
    Texture2D runningSpriteSheet = LoadTexture("assets/Run.PNG");
    Texture2D Background = LoadTexture("assets/peakpx.png");
    Texture2D Box = LoadTexture("assets/box.png");

    //Camera 
    Camera2D camera = {0};
    camera.target = player.position;
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
    camera.offset = (Vector2){ screenWidth / 2.0f-375, screenHeight / 2.0f };
    Vector2 screenPlayerPosition = {
        camera.offset.x, // Keep the player horizontally fixed
        player.position.y // Use the actual Y position
    };
    // Set the target FPS (frames per second)
    SetTargetFPS(60);
    while(!started){  //Loop for main menu
        ;
    }
    while(started && !WindowShouldClose()){ //Loop for actual game
        camera.target = player.position;
        summoningBox(boxes);
        
        changePlayerState(&player, runningFrameCount, currentRunningFrame);
        PlayerMovement(&player);
        BeginDrawing();
        ClearBackground(BROWN);
        DrawTexture(Background, 0, 0, WHITE);
        if(player.isRunning){
            runningFrameCount+=1;
            UpdateFrame(&runningFrameCount, &currentRunningFrame);
            DrawSprite(runningSpriteSheet, currentRunningFrame, player, screenPlayerPosition);
        }
        else if(!player.isRunning){
            DrawIdleMan(IdleMan, player);
        }
        renderBox(boxes, Box);
        BeginMode2D(camera);
        // Calculate the background's scrolling offset based on the player's position
        EndMode2D();
        EndDrawing();
    }
    free(boxes);
    for (int i = 0; i < TOTAL_BOX; i++) {
        free(boxes[i]); // Free each allocated box
    }

    CloseWindow();
    return 0;
}