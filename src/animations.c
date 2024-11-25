#include <raylib.h>
#include "../include/gameMechanics.h"
#include "../include/animations.h"
#include "../include/renderTerrain.h"

void DrawIdleMan(Texture2D t, Player player){
    DrawTextureEx(t, player.position, 0.0f, 3.0f, WHITE);
}