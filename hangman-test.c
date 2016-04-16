#include "libhangman.h"
#include <testing.h>

TEST(hangman, it_should_begin_with_empty_state) {
  EXPECT_INT_EQ(hm_current_state, HM_STATE_EMPTY);
}

TEST(hangman, it_should_draw_base_when_select_miss_character) {
  hm_current_state = HM_STATE_EMPTY;

  hm_set_word("HANGMAN");
  hm_guess_character('B');

  EXPECT_INT_EQ(hm_current_state, HM_STATE_DRAW_BASE);
}

TEST(hangman, it_should_change_state_when_guess_correct_character) {
  hm_current_state = HM_STATE_EMPTY;

  hm_set_word("HANGMAN");
  hm_guess_character('H');

  EXPECT_INT_EQ(hm_current_state, HM_STATE_EMPTY);
}

TEST(hangman, it_should_change_state_to_draw_head_when_guess_wrong_2_times) {
  hm_current_state = HM_STATE_EMPTY;

  hm_set_word("HANGMAN");
  hm_guess_character('B');
  hm_guess_character('B');

  EXPECT_INT_EQ(hm_current_state, HM_STATE_DRAW_HEAD);
}

START_RUN_TESTS {
  TEST_ENTRY(hangman, it_should_begin_with_empty_state)
  TEST_ENTRY(hangman, it_should_draw_base_when_select_miss_character)
  TEST_ENTRY(hangman, it_should_change_state_when_guess_correct_character)
  TEST_ENTRY(hangman,
             it_should_change_state_to_draw_head_when_guess_wrong_2_times)
}
END_RUN_TESTS
