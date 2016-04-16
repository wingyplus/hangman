cmake_minimum_required(VERSION 3.0)
project(hangman C)

include_directories(libs/libtesting/include libs/cmocka/include)

# add_library(hangman STATIC hangman.c)
add_executable(hangman-test hangman-test.c hangman.c)
target_link_libraries(hangman-test cmocka)

enable_testing()
add_test(hangman-test hangman-test)
