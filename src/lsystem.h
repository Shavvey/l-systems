#ifndef INCLUDE_SRC_LSYSTEM_H_
#define INCLUDE_SRC_LSYSTEM_H_

#include <stddef.h>
#include "turtle.h"
// for now, a token is really just a wrapper for an ASCII char...
typedef char Token;

// maps actions a the turtle will do with the given input token
typedef struct _Codec {
 Token t;
 void (*turtleAction)(Turtle *t);
}Codec;

// lsystem needs a sized list to preform a linear search on
typedef struct _CodecList {
  const Codec *codecs;
  size_t size;
}CodecList;

// transforms a single token into an array of many tokens
typedef struct _Rule {
  const Token input;
  const Token *output;
} Rule;

// needed a sized list of rules for the lsystem
typedef struct _RuleList {
  const Rule *rules;
  size_t size;
} RuleList;

typedef struct _LSystem {
  Token axiom; // starting atomic to apply rules to
  const RuleList rlist;
  const CodecList clist;
} LSystem;

// API
void display_lsys(const LSystem *l);
#endif  // INCLUDE_SRC_LSYSTEM_H_
