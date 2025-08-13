#include "../include/raylib.h"
#include "common.h"
#include "turtle.h"
#include <stdlib.h>

// needed to know which lsystem is currently implemented
#include "lsystem.h"
#include "rules/btree.h"

int main(void) {
  SetConfigFlags(FLAG_WINDOW_RESIZABLE);
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
  SetTargetFPS(60);
  display_lsys(&LSYSTEM);
  TokenStream ts = make_tsream(&LSYSTEM);
  // main game loop
  while (!WindowShouldClose()) {
    ClearBackground(BLACK);
    if (IsKeyPressed(KEY_N)) {
      ts = recurse(&LSYSTEM, &ts);
    }
    BeginDrawing();
    Turtle t = make_turtle(DEF_XPOS, DEF_YPOS, DEF_COLOR);
    draw_tstream(&LSYSTEM.clist, &ts, &t);
    EndDrawing();
  }
  CloseWindow();
  return EXIT_SUCCESS;
}
