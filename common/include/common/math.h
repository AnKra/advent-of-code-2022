#ifndef ADVENT_OF_CODE_2022_COMMON_MATH_H_
#define ADVENT_OF_CODE_2022_COMMON_MATH_H_

namespace common {

inline int positive_modulo(int i, int n) { return (i % n + n) % n; }

inline int move_into_range(int i, int n, int min, int max) {
  if (i < min) {
    return i + n;
  }
  if (i > max) {
    return i - n;
  }
  return i;
}

} // namespace common

#endif // ADVENT_OF_CODE_2022_COMMON_MATH_H_
