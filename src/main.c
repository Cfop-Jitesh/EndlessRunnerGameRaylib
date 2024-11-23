//Libraries
#include <raylib.h>
#include <stdlib.h>
#include "../include/game.h"
#include "../include/input.h"
#include "../include/render.h"

//Main Function
int main(){
    bool started = true;
    const int screenWidth = 800;  // Screen width
    const int screenHeight = 600; // Screen height

    // Initialize the window
    InitWindow(screenWidth, screenHeight, "Runner");

    // Set the target FPS (frames per second)
    SetTargetFPS(60);
    while(!started){  //Loop for main menu
        ;
    }
    while(started){ //Loop for actual game
        BeginDrawing();
        ClearBackground(RAYWHITE);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}