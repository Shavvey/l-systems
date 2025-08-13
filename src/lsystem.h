#ifndef INCLUDE_SRC_LSYSTEM_H_
#define INCLUDE_SRC_LSYSTEM_H_
#include "common.h"

typedef struct _Rule {
  const char *input;
  const char *output;
} Rule;

typedef struct _LSystem {
  const Rule *rules; // how to permute input
  const char axiom; // starting condition of system
}LSystem;


// API
LSystem parse_system(const char *config_file);
void apply_rule(LSystem *lsys, StringBuilder* input);
#endif  // INCLUDE_SRC_LSYSTEM_H_
