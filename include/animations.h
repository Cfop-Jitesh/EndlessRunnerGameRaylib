#ifndef ANIMATIONS_H
#define ANIMATIONS_H

#include "raylib.h"
#include "gameMechanics.h"

// Function to draw idle animation of the player
void DrawIdleMan(Texture2D t, Player player);
void UpdateFrame(int* frameCount, int* currentFrame);
void DrawSprite(Texture2D spriteSheet, int spriteIndex, Player player);
#endif
