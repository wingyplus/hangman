#include "libhangman.h"
#include <string.h>

HMState hm_current_state = HMState_Empty;
static char word[100];

static HMState next_state(HMState state) {
  switch (state) {
  case HMState_Empty:
    return HMState_DrawBase;
  case HMState_DrawBase:
    return HMState_DrawHead;
  case HMState_DrawHead:
    return HMState_DrawBody;
  case HMState_DrawBody:
    return HMState_DrawRightHand;
  default:
    return HMState_DrawLeftHand;
  }
}

void hm_set_word(const char *w) { strcpy(word, w); }

void hm_guess_character(const char ch) {
  if (strchr(word, ch) == NULL) {
    hm_current_state = next_state(hm_current_state);
  }
}
