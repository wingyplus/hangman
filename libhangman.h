#ifndef LIBHANGMAN_H_
#define LIBHANGMAN_H_

typedef enum {
  HMState_Empty,
  HMState_DrawBase,
  HMState_DrawHead,
  HMState_DrawBody,
  HMState_DrawRightHand,
  HMState_DrawLeftHand
} HMState;

extern HMState hm_current_state;

void hm_set_word(const char *);
void hm_guess_character(const char);

#endif // LIBHANGMAN_H_
