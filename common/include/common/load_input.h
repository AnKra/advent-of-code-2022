#ifndef ADVENT_OF_CODE_2022_COMMON_LOAD_INPUT_H_
#define ADVENT_OF_CODE_2022_COMMON_LOAD_INPUT_H_

#include <istream>
#include <iterator>
#include <string>

namespace common {

class Line : public std::string {
  friend std::istream &operator>>(std::istream &is, Line &line) {
    return std::getline(is, line);
  }
};

template <class T, class OutputIterator>
void read_lines(std::istream &is, OutputIterator dest) {
  typedef std::istream_iterator<T> InputIterator;
  std::copy(InputIterator(is), InputIterator(), dest);
}

} // namespace common

#endif // ADVENT_OF_CODE_2022_COMMON_LOAD_INPUT_H_
