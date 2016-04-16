#ifndef LIBHANGMAN_H_
#define LIBHANGMAN_H_

enum HM_STATE {
  HM_STATE_EMPTY,
  HM_STATE_DRAW_BASE,
  HM_STATE_DRAW_HEAD
};

extern enum HM_STATE hm_current_state;

void hm_set_word(const char*);
void hm_guess_character(const char);

#endif // LIBHANGMAN_H_
