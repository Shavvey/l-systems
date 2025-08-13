#include "hstack.h"
#include "common.h"
#include <stdlib.h>

HStack make_hstack(size_t capacity) {
  HStack hs = {.capacity = capacity,
               .size = 0,
               .top_idx = 0,
               .items = (History *)malloc(sizeof(History) * capacity)};
  return hs;
}

void push(HStack *hs, History hist) {
  hs->items[hs->size] = hist;
  hs->size++;
  hs->top_idx++;
}

History pop(HStack *hs) {
  if (hs->size == 0) {
    eprintf("[ERROR]: Stack is empty!");
    // NOTE: consider just killing the process if this happens...
    History h = {0};
    return h;
  } else {
    History h = hs->items[hs->size];
    hs->size--;
    return h;
  }
}
