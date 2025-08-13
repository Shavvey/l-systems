#include "turtle.h"
#include "../include/raylib.h"
#include <math.h>

void draw_linseg(Turtle *turtle) {
  int endx = DEF_LSEG_LEN * cos((float) turtle->angle);
  int endy = DEF_LSEG_LEN * sin((float) turtle->angle);
  int startx = turtle->xpos;
  int starty = turtle->ypos;
  DrawLine(startx, starty, endx, endy,);
}
