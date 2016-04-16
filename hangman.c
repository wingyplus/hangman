#include <string.h>
#include "libhangman.h"

enum HM_STATE hm_current_state = HM_STATE_EMPTY;
static char word[100];

static enum HM_STATE next_state(enum HM_STATE state) {
  if (state == HM_STATE_EMPTY) {
    return HM_STATE_DRAW_BASE;
  }
  return HM_STATE_DRAW_HEAD;
}

void hm_set_word(const char *w) {
  strcpy(word, w);
}

void hm_guess_character(const char ch) {
  if (strchr(word, ch) == NULL) {
    hm_current_state = next_state(hm_current_state);
  }
}
