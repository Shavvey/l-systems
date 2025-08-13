#ifndef INCLUDE_SRC_TURTLE_H_
#define INCLUDE_SRC_TURTLE_H_
#include "../include/raylib.h"
#include "common.h"
#define DEF_LSEG_LEN 10
#define DEF_XPOS SCREEN_WIDTH / 2 
#define DEF_YPOS SCREEN_HEIGHT
typedef struct _Turtle {
  int xpos;
  int ypos;
  int angle;
  Color draw_color;
}Turtle;
// API
Turtle make_turtle(int xpos, int ypos);
void draw_lineseg(Turtle *turtle);
#endif  // INCLUDE_SRC_TURTLE_H_
