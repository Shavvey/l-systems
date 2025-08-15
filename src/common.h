#ifndef INCLUDE_SRC_COMMON_H_
#define INCLUDE_SRC_COMMON_H_
#define SCREEN_WIDTH 1500
#define SCREEN_HEIGHT 1000
#define WINDOW_TITLE "l-systems"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#define eprintf(...) do { fprintf(stderr, __VA_ARGS__); }while(0)
#define UNIMPLEMENTED(...)                                           \
do {                                                                 \
  printf("%s:%d UNIMPLEMENTED %s", __FILE__, __LINE__, __VA_ARGS__); \
  exit(1);                                                           \
}while(0)

#define AL_RESIZE_INC 1 << 3

#define alist_last(al) (al)->items[(al)->size-1]

#define alist_append(al, item) do {                                          \
  if ((al)->capacity - (al)->size == 0) {                                    \
    (al)->capacity += AL_RESIZE_INC;                                         \
    (al)->items = realloc((al)->items, (al)->capacity*sizeof(*(al)->items)); \
    assert((al)->items != NULL && "[ERROR]: Array list alloc failed!");      \
  }                                                                          \
  (al)->items[(al)->size++] = (item);                                        \
}while(0)

#define alist_append_many(al, new_items, size) do {  \
  size_t i = 0;                                      \
  while(i < (size)) {                                \
     alist_append((al), (new_items)[i]);             \
     i++;                                            \
  }                                                  \
}while(0)

#define alist_delete_at(al, idx) do {         \
  if ((idx) < 0 || (idx) >= (al)->size) {     \
    eprintf("[ERROR]: Out of range!");        \
  }                                           \
  for (size s = (idx); i < (al)->size; s++) { \
       (al)->items[i] = (al)->items[i+1];     \
  }                                           \
  (al)->size--;                               \
}while(0)

#define alist_free(al) do {   \
 (al)->size = 0;              \
 (al)->capacity = 0;          \
 free((al)->items);           \
}while(0)

#endif  // INCLUDE_SRC_COMMON_H_
