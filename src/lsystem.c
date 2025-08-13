#include "lsystem.h"
#include "common.h"
#include <stdio.h>
#include <string.h>

void display_lsys(const LSystem *ls) {
  printf("Starting axiom: %c\n", ls->axiom);
  for (size_t rs = 0; rs < ls->rlist.size; rs++) {
    Rule r = ls->rlist.rules[rs];
    printf("%zu:%c => %s\n", rs, r.input, r.output);
  }
  for (size_t cs = 0; cs < ls->clist.size; cs++) {
    Codec c = ls->clist.codecs[cs];
    printf("%zu:%c => %p\n", cs, c.t, c.turtleAction);
  }
}

void print_tstream(const TokenStream *ts) {
  for (size_t s = 0; s < ts->size; s++) {
    printf("%c", ts->items[s]);
  }
  printf("\n");
}

TokenStream make_tsream(const LSystem *l) {
  const int AXIOM_LEN = 1;
  TokenStream ts = {.capacity = AXIOM_LEN,
                    .items = (Token *)malloc(sizeof(Token) * AXIOM_LEN),
                    .size = 0};
  alist_append(&ts, l->axiom);
  return ts;
}

static const Token *apply_rule(const RuleList *rl, const Token t) {
  for (size_t rs = 0; rs < rl->size; rs++) {
    Rule r = rl->rules[rs];
    if (r.input == t) {
      return r.output;
    }
  }
  return NULL;
}
/** NOTE: this function is a little wasteful because we throw away
  the original token stream each iteration, consider
  making this function A LOT better by modifying instead of
  rebuilding the token stream **/
TokenStream recurse(const LSystem *l, TokenStream *ts) {
  Token *tokens = ts->items;
  size_t token_size = ts->size;
  TokenStream nts = {.capacity = token_size,
                     .size = 0,
                     .items = (Token *)malloc(sizeof(Token) * token_size)};
  for (size_t ts = 0; ts < token_size; ts++) {
    Token token = tokens[ts];
    const Token *new_tokens = apply_rule(&l->rlist, token);
    printf("%c => %s\n", token, new_tokens);
    alist_append_many(&nts, new_tokens, strlen(new_tokens));
  }
  alist_free(ts);
  return nts;
}
