#ifndef INCLUDE_SRC_HSTACK_H_
#define INCLUDE_SRC_HSTACK_H_

#include <stddef.h>
typedef struct _History {
  int xpos;
  int ypos;
  int angle;
} History;

typedef struct _HStack {
  History *items;
  size_t capacity;
  size_t size;
  size_t top_idx;
} HStack;

// API
HStack make_hstack(size_t capacity);
void push(HStack *hs, History hist);
History pop(HStack *hs);
#endif  // INCLUDE_SRC_HSTACK_H_
