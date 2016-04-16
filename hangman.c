#include <string.h>
#include "libhangman.h"

HMState hm_current_state = HMState_Empty;
static char word[100];

static HMState next_state(HMState state) {
  if (state == HMState_Empty) {
    return HMState_DrawBase;
  }
  return HMState_DrawHead;
}

void hm_set_word(const char *w) {
  strcpy(word, w);
}

void hm_guess_character(const char ch) {
  if (strchr(word, ch) == NULL) {
    hm_current_state = next_state(hm_current_state);
  }
}
