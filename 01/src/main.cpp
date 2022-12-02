#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

#include <common/load_input.h>

int main() {
  // read calories
  std::vector<std::string> lines;
  std::ifstream is("../input/input.txt");
  common::read_lines<common::Line>(is, std::back_inserter(lines));

  // calculate calories per elf
  std::vector<int> calories;

  auto sum = 0;
  for (auto line : lines) {
    if (!line.empty()) {
      sum += std::stoi(line);
    } else {
      calories.push_back(sum);
      sum = 0;
    }
  }

  // retrieve max calories value
  auto max_calories =
      *std::max_element(std::begin(calories), std::end(calories));
  std::cout << "Part 1: " << max_calories << std::endl;

  // retrieve 3 max calories values
  auto sum_max_calories = 0;
  for (int i = 0; i < 3; ++i) {
    auto max_element =
        std::max_element(std::begin(calories), std::end(calories));
    sum_max_calories += *max_element;
    calories.erase(max_element);
  }
  std::cout << "Part 2: " << sum_max_calories << std::endl;

  std::cout << "done" << std::endl;
}
