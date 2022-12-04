#include <gtest/gtest.h>

#include "solution.h"

TEST(Test, Part1) {
  EXPECT_EQ(2, day04::part1("../input/test_input.txt"));
  EXPECT_EQ(599, day04::part1("../input/input.txt"));
}

// TEST(Test, Part2) {
//   EXPECT_EQ(0, day04::part2("../input/test_input.txt"));
//   EXPECT_EQ(0, day04::part2("../input/input.txt"));
// }
