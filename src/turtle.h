#ifndef INCLUDE_SRC_TURTLE_H_
#define INCLUDE_SRC_TURTLE_H_
#include "../include/raylib.h"
#include "common.h"

#define INIT_LSEG_LEN 50
#define DEF_XPOS SCREEN_WIDTH / 2 
#define DEF_YPOS SCREEN_HEIGHT
#define DEF_COLOR GREEN

typedef struct _History {
  int xpos;
  int ypos;
  int angle;
} History;

typedef struct _HStack {
  History *items;
  size_t capacity;
  size_t size;
} HStack;

typedef struct _Turtle {
  int xpos;
  int ypos;
  int angle;
  Color draw_color;
  int seg_length;
  HStack history; // record previous configs of turtle
}Turtle;

// API
HStack make_hstack(size_t capacity);
void push(HStack *hs, History hist);
History pop(HStack *hs);
Turtle make_turtle(int xpos, int ypos, Color color);
void draw_lineseg(Turtle *turtle);
void reset(Turtle *turtle, History h);
#endif  // INCLUDE_SRC_TURTLE_H_
