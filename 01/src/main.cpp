#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <numeric>
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
  calories.push_back(sum); // add last item

  // retrieve max calories value
  auto max_calories =
      *std::max_element(std::cbegin(calories), std::cend(calories));
  std::cout << "Part 1: " << max_calories << std::endl;

  // retrieve 3 max calories values
  std::nth_element(calories.begin(), calories.begin() + 3, calories.end(),
                   std::greater{});
  auto sum_max_calories =
      std::accumulate(calories.cbegin(), calories.cbegin() + 3, 0);
  std::cout << "Part 2: " << sum_max_calories << std::endl;

  std::cout << "done" << std::endl;
}
