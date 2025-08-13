#include "../include/raylib.h"
#include "common.h"
#include "turtle.h"
#include <stdlib.h>

int main(void) {
  SetConfigFlags(FLAG_WINDOW_RESIZABLE);
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
  SetTargetFPS(60);

  // main game loop
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BLACK);
    Turtle t = make_turtle(DEF_XPOS, DEF_YPOS, DEF_COLOR);
    draw_lineseg(&t);
    EndDrawing();
  }
  CloseWindow();
  return EXIT_SUCCESS;
}
