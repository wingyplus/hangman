#include "libhangman.h"
#include <testing.h>

TEST(hangman, it_should_begin_with_empty_state) {
  EXPECT_INT_EQ(hm_current_state, HMState_Empty);
}

TEST(hangman, it_should_draw_base_when_select_miss_character) {
  hm_current_state = HMState_Empty;

  hm_set_word("HANGMAN");
  hm_guess_character('B');

  EXPECT_INT_EQ(hm_current_state, HMState_DrawBase);
}

TEST(hangman, it_should_change_state_when_guess_correct_character) {
  hm_current_state = HMState_Empty;

  hm_set_word("HANGMAN");
  hm_guess_character('H');

  EXPECT_INT_EQ(hm_current_state, HMState_Empty);
}

TEST(hangman, it_should_change_state_to_draw_head_when_guess_wrong_2_times) {
  hm_current_state = HMState_Empty;

  hm_set_word("HANGMAN");
  hm_guess_character('B');
  hm_guess_character('B');

  EXPECT_INT_EQ(hm_current_state, HMState_DrawHead);
}

TEST(hangman, it_should_draw_body_after_draw_head) {
  hm_current_state = HMState_DrawHead;

  hm_set_word("HANGMAN");
  hm_guess_character('B');

  EXPECT_INT_EQ(hm_current_state, HMState_DrawBody);
}

TEST(hangman, it_should_draw_right_hand_after_draw_body) {
  hm_current_state = HMState_DrawBody;

  hm_set_word("HANGMAN");
  hm_guess_character('B');

  EXPECT_INT_EQ(hm_current_state, HMState_DrawRightHand);
}

TEST(hangman, it_should_draw_left_hand_after_draw_body) {
  hm_current_state = HMState_DrawRightHand;

  hm_set_word("HANGMAN");
  hm_guess_character('B');

  EXPECT_INT_EQ(hm_current_state, HMState_DrawLeftHand);
}

START_RUN_TESTS {
  TEST_ENTRY(hangman, it_should_begin_with_empty_state)
  TEST_ENTRY(hangman, it_should_draw_base_when_select_miss_character)
  TEST_ENTRY(hangman, it_should_change_state_when_guess_correct_character)
  TEST_ENTRY(hangman,
             it_should_change_state_to_draw_head_when_guess_wrong_2_times)
  TEST_ENTRY(hangman, it_should_draw_body_after_draw_head)
  TEST_ENTRY(hangman, it_should_draw_right_hand_after_draw_body)
  TEST_ENTRY(hangman, it_should_draw_left_hand_after_draw_body)
}
END_RUN_TESTS
