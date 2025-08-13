#include "../include/raylib.h"
#include "common.h"
#include <stdlib.h>

int main(void) {
  SetConfigFlags(FLAG_WINDOW_RESIZABLE);
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
  SetTargetFPS(60);

  // main game loop
  while (!WindowShouldClose()) {
    BeginDrawing();
    // draw all the objects here!
    ClearBackground(BLACK);
    DrawLine(SCREEN_WIDTH / 2, SCREEN_HEIGHT, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, RAYWHITE);
    EndDrawing();
  }
  CloseWindow();
  return EXIT_SUCCESS;
}
