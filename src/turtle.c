#include "turtle.h"
#include "../include/raylib.h"
#include <math.h>

Turtle make_turtle(int xpos, int ypos, Color color) {
  Turtle t = {.xpos = xpos,
              .ypos = ypos,
              .angle = 90,
              .history = make_hstack(1 << 8), // NOTE: figure out how to anticipate history size needed
              .draw_color = color};
  return t;
}

void draw_lineseg(Turtle *turtle) {
  int endx = turtle->xpos - DEF_LSEG_LEN * cos((float)turtle->angle * PI / 180);
  int endy = turtle->ypos - DEF_LSEG_LEN * sin((float)turtle->angle * PI / 180);
  int startx = turtle->xpos;
  int starty = turtle->ypos;
  DrawLine(startx, starty, endx, endy, turtle->draw_color);
}

HStack make_hstack(size_t capacity) {
  HStack hs = {.capacity = capacity,
               .size = 0,
               .items = (History *)malloc(sizeof(History) * capacity)};
  return hs;
}

void push(HStack *hs, History hist) {
  hs->items[hs->size - 1] = hist;
  hs->size++;
}

History pop(HStack *hs) {
  if (hs->size == 0) {
    eprintf("[ERROR]: Stack is empty!");
    // NOTE: consider just killing the process if this happens...
    History h = {0};
    return h;
  } else {
    History h = hs->items[hs->size - 1];
    hs->size--;
    return h;
  }
}
