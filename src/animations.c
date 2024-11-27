#include <raylib.h>
#include <stdio.h>
#include "../include/gameMechanics.h"
#include "../include/animations.h"
#include "../include/renderTerrain.h"

void DrawIdleMan(Texture2D t, Player player){
    DrawTextureEx(t, player.position, 0.0f, 3.0f, WHITE);
}

void UpdateFrame(int* frameCount, int* currentFrame){
    if(*frameCount >= 6){
        *currentFrame = (*currentFrame)+1;
        if(*currentFrame>7){
            *currentFrame = 0;
        }
        *frameCount = 0;
    }
}

void DrawSprite(Texture2D spriteSheet, int spriteIndex, Player player,Vector2 ScreenPlayerPosition) {
    // Define sprite dimensions
    int spriteH = 0+(32*spriteIndex);
    Rectangle source = {spriteH, spriteH+32, 32, 32};
    Rectangle dest = {
        .x = ScreenPlayerPosition.x,
        .y = player.position.y,
        .height = 114,
        .width = 114
    };
    Vector2 origin = {16,16};
    DrawTexturePro(spriteSheet, source, dest, origin, 0.0f, WHITE);

}

void renderBox(box* boxes[], Texture2D t){
    int i = 0;
    if(i<TOTAL_BOX){
        DrawTextureEx(t, boxes[i]->position, 0.0f, 4.0, WHITE);
        i+=1;
    }
}
