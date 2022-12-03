#ifndef ADVENT_OF_CODE_2022_01_SOLUTION_H_
#define ADVENT_OF_CODE_2022_01_SOLUTION_H_

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <numeric>
#include <string>
#include <vector>

#include <common/load_input.h>

namespace day01 {

std::vector<int> calories;

int part1(const std::string &input_file) {
  // read calories
  std::vector<std::string> lines;
  std::ifstream is(input_file);
  common::read_lines<common::Line>(is, std::back_inserter(lines));

  // calculate calories per elf
  auto sum = 0;
  for (auto line : lines) {
    if (!line.empty()) {
      sum += std::stoi(line);
    } else {
      calories.push_back(sum);
      sum = 0;
    }
  }
  calories.push_back(sum); // add last item

  // retrieve max calories value
  auto max_calories =
      *std::max_element(std::cbegin(calories), std::cend(calories));
  return max_calories;
}

int part2(const std::string & /*input_file */) {
  // retrieve 3 max calories values
  std::nth_element(calories.begin(), calories.begin() + 3, calories.end(),
                   std::greater{});
  auto sum_max_calories =
      std::accumulate(calories.cbegin(), calories.cbegin() + 3, 0);
  return sum_max_calories;
}

} // namespace day01

#endif // ADVENT_OF_CODE_2022_01_SOLUTION_H_
