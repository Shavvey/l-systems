#include "../include/raylib.h"
#include "common.h"
#include "turtle.h"
#include <stdlib.h>

// needed to know which lsystem is currently implemented
#include "lsystem.h"
#include "rules/btree.h"

int main(void) {
  // SetConfigFlags(FLAG_WINDOW_RESIZABLE);
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
  SetTargetFPS(60);
  display_lsys(&LSYSTEM);
  TokenStream ts = make_tsream(&LSYSTEM);
  print_tstream(&ts);
  ts = recurse(&LSYSTEM, &ts);
  print_tstream(&ts);
  // main game loop
  while (!WindowShouldClose()) {
    ClearBackground(BLACK);
    Turtle t = make_turtle(DEF_XPOS, DEF_YPOS, DEF_COLOR);
    BeginDrawing();
    draw_tstream(&LSYSTEM.clist, &ts, &t);
    EndDrawing();
  }
  CloseWindow();
  return EXIT_SUCCESS;
}
