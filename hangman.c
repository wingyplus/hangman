#include <string.h>
#include "libhangman.h"

enum HM_STAGE hm_current_stage = HM_STAGE_EMPTY;
static char word[100];

void hm_set_word(const char *w) {
  strcpy(word, w);
}

void hm_guess_character(const char ch) {
  if (strchr(word, ch) == NULL) {
    hm_current_stage = HM_STAGE_DRAW_BASE;
  }
}
