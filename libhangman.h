#ifndef LIBHANGMAN_H_
#define LIBHANGMAN_H_

enum HM_STAGE {
  HM_STAGE_EMPTY,
  HM_STAGE_DRAW_BASE
};

extern enum HM_STAGE hm_current_stage;

void hm_set_word(const char*);
void hm_guess_character(const char);

#endif // LIBHANGMAN_H_
