#include "../include/raylib.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 500

#define WINDOW_TITLE "l-systems"

int main(void) {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
  SetTargetFPS(60);


  while (!WindowShouldClose()) {
    BeginDrawing();

    ClearBackground(BLACK);
    Ray r = {.position = {.x = 0, .y = 1}, .direction = {.x = 3, .y = 3}};
    DrawRay(r, WHITE);


    EndDrawing();
  }
  CloseWindow();
  return 0;
}
