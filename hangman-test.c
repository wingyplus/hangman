#include <testing.h>
#include "libhangman.h"

TEST(hangman, it_should_begin_with_empty_stage) {
  EXPECT_INT_EQ(hm_current_stage, HM_STAGE_EMPTY);
}

TEST(hangman, it_should_draw_base_when_select_miss_character) {
  hm_current_stage = HM_STAGE_EMPTY;

  hm_set_word("HANGMAN");
  hm_guess_character('B');

  EXPECT_INT_EQ(hm_current_stage, HM_STAGE_DRAW_BASE);
}

TEST(hangman, it_should_change_stage_when_guess_correct_character) {
  hm_current_stage = HM_STAGE_EMPTY;

  hm_set_word("HANGMAN");
  hm_guess_character('H');

  EXPECT_INT_EQ(hm_current_stage, HM_STAGE_EMPTY);
}

START_RUN_TESTS {
  TEST_ENTRY(hangman, it_should_begin_with_empty_stage)
  TEST_ENTRY(hangman, it_should_draw_base_when_select_miss_character)
  TEST_ENTRY(hangman, it_should_change_stage_when_guess_correct_character)
}
END_RUN_TESTS
