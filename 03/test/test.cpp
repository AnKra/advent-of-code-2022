#include <gtest/gtest.h>

#include "solution.h"

TEST(Test, Part1) {
  EXPECT_EQ(157, day03::part1("../input/test_input.txt"));
  EXPECT_EQ(7821, day03::part1("../input/input.txt"));
}

TEST(Test, Part2) {
  EXPECT_EQ(70, day03::part2("../input/test_input.txt"));
  EXPECT_EQ(2752, day03::part2("../input/input.txt"));
}
