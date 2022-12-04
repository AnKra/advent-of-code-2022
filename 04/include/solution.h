#ifndef ADVENT_OF_CODE_2022_04_SOLUTION_H_
#define ADVENT_OF_CODE_2022_04_SOLUTION_H_

#include <algorithm>
#include <fstream>
#include <ranges>
#include <set>
#include <string>
#include <string_view>
#include <vector>

#include <common/load_input.h>

namespace day04 {

std::set<int> expand(std::string_view s) {
  auto first = atoi(s.substr(0, s.find('-')).data());
  auto last = atoi(s.substr(s.find('-') + 1).data());

  std::set<int> sequence;
  std::generate_n(std::inserter(sequence, sequence.begin()), last - first + 1,
                  [&first]() { return first++; });

  return sequence;
}

int part1(const std::string &input_file) {
  // read section assignments
  std::vector<std::string> lines;
  std::ifstream is(input_file);
  common::read_lines<common::Line>(is, std::back_inserter(lines));

  // identify overlapping assignent pairs
  int overlapping_assignment_pairs = 0;
  for (auto &line : lines) {
    auto view =
        line | std::ranges::views::split(',') |
        std::ranges::views::transform([](auto &&rng) {
          return std::string_view(&*rng.begin(), std::ranges::distance(rng));
        });

    auto first_sequence = expand(*view.begin());
    auto second_sequence = expand(*std::next(view.begin(), 1));

    if (std::includes(first_sequence.begin(), first_sequence.end(),
                      second_sequence.begin(), second_sequence.end()) ||
        std::includes(second_sequence.begin(), second_sequence.end(),
                      first_sequence.begin(), first_sequence.end())) {
      ++overlapping_assignment_pairs;
    }
  }

  return overlapping_assignment_pairs;
}

// int part2(const std::string &input_file) { return 0; }

} // namespace day04

#endif // ADVENT_OF_CODE_2022_04_SOLUTION_H_
