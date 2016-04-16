#include "libhangman.h"
#include <stdlib.h>
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
  case HMState_DrawRightHand:
    return HMState_DrawLeftHand;
  case HMState_DrawLeftHand:
    return HMState_DrawRightLeg;
  case HMState_DrawRightLeg:
    return HMState_DrawLeftLeg;
  default:
    return HMState_GameOver;
  }
}

void hm_set_word(const char *w) { strlcpy(word, w, sizeof(word)); }

void hm_guess_character(const char ch) {
  if (strchr(word, ch) == NULL) {
    hm_current_state = next_state(hm_current_state);
  }
}
