#ifndef LIBHANGMAN_H_
#define LIBHANGMAN_H_

typedef enum {
  HMState_Empty,
  HMState_DrawBase,
  HMState_DrawHead,
  HMState_DrawBody,
  HMState_DrawRightHand,
  HMState_DrawLeftHand,
  HMState_DrawRightLeg,
  HMState_DrawLeftLeg,
  HMState_GameOver
} HMState;

extern HMState hm_current_state;

void hm_set_word(const char *);
void hm_guess_character(const char);
char * hm_display_word();

#endif // LIBHANGMAN_H_
