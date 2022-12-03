#ifndef ADVENT_OF_CODE_2022_03_SOLUTION_H_
#define ADVENT_OF_CODE_2022_03_SOLUTION_H_

#include <cassert>
#include <fstream>
#include <map>
#include <numeric>
#include <string>
#include <vector>

#include <common/load_input.h>

namespace day03 {

static char commonChar(const std::string &s1, const std::string &s2) {
  for (char const &c : s1) {
    if (s2.find(c) != std::string::npos) {
      return c;
    }
  }

  throw std::runtime_error("No common characters found");
}

static std::string commonChars(const std::string &s1, const std::string &s2) {
  std::string common_chars;
  for (char const &c : s1) {
    if (s2.find(c) != std::string::npos) {
      common_chars += c;
    }
  }

  return common_chars;
}

static char findSharedItem(const std::string &rucksack_items) {
  auto number_of_items = rucksack_items.length();

  auto comaprtment1 = rucksack_items.substr(0, number_of_items / 2);
  auto comaprtment2 = rucksack_items.substr(number_of_items / 2);

  return commonChar(comaprtment1, comaprtment2);
}

static int toPriority(char c) {
  if (c >= 'a' && c <= 'z') {
    return c - 'a' + 1;
  }
  if (c >= 'A' && c <= 'Z') {
    return c - 'A' + 27;
  }

  throw std::runtime_error("Unknown rucksack item");
}

static char findBadge(const std::vector<std::string> &group) {
  auto common_chars = commonChars(group[0], group[1]);
  return commonChar(common_chars, group[2]);
}

int part1(const std::string &input_file) {
  // read rucksacks
  std::vector<std::string> lines;
  std::ifstream is(input_file);
  common::read_lines<common::Line>(is, std::back_inserter(lines));

  // find shared items
  std::map<char, int> shared_items;
  std::for_each(lines.begin(), lines.end(), [&shared_items](const auto &line) {
    shared_items[findSharedItem(line)]++;
  });

  // transform share_items to priorities
  std::vector<int> priorities;
  std::transform(shared_items.cbegin(), shared_items.cend(),
                 std::back_inserter(priorities), [](auto pair) {
                   return pair.second * toPriority(pair.first);
                 });

  // accumulate priorities
  return std::accumulate(std::begin(priorities), std::end(priorities), 0);
}

int part2(const std::string &input_file) {
  // read rucksacks
  std::vector<std::string> lines;
  std::ifstream is(input_file);
  common::read_lines<common::Line>(is, std::back_inserter(lines));

  // split up into groups
  auto group_size = 3;
  std::vector<std::vector<std::string>> groups;
  for (size_t i = 0; i < lines.size(); i += group_size) {
    assert(i + group_size <= lines.size());
    groups.emplace_back(lines.begin() + i, lines.begin() + i + group_size);
  }

  // find badge
  std::vector<char> badges;
  std::transform(groups.cbegin(), groups.cend(), std::back_inserter(badges),
                 [](const auto &group) { return findBadge(group); });

  // accumulate priorities
  return std::accumulate(std::begin(badges), std::end(badges), 0,
                         [&](double previous, double badge) {
                           return previous + toPriority(badge);
                         });
}

} // namespace day03

#endif // ADVENT_OF_CODE_2022_03_SOLUTION_H_
