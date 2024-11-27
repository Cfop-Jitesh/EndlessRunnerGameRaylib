//Libraries
#include <raylib.h>
#include <stdio.h>
#include <math.h>
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
    Texture2D Background = LoadTexture("assets/peakpx.png");


    //Camera 
    Camera2D camera = {0};
    camera.target = player.position;
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
    camera.offset = (Vector2){ screenWidth / 2.0f, screenHeight / 2.0f };
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
        printf("Player Position: (%f, %f)\n", player.position.x, player.position.y);
        printf("Camera Target: (%f, %f)\n", camera.target.x, camera.target.y);

        if(player.isRunning){
            runningFrameCount+=1;
            UpdateFrame(&runningFrameCount, &currentRunningFrame);
            DrawSprite(runningSpriteSheet, currentRunningFrame, player, screenPlayerPosition);
        }
        else if(!player.isRunning){
            DrawIdleMan(IdleMan, player);
        }
        changePlayerState(&player, runningFrameCount, currentRunningFrame);
        PlayerMovement(&player);
        BeginDrawing();
        ClearBackground(BROWN);
        BeginMode2D(camera);
        // Calculate the background's scrolling offset based on the player's position
        float bgX = fmod(player.position.x, Background.width);
        
        // Draw the background twice to ensure seamless looping
        DrawTexture(Background, -bgX, 0, WHITE); 
        DrawTexture(Background, -bgX + Background.width, 0, WHITE);


        EndMode2D();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}