#include <fstream>
#include <iostream>
#include <iterator>
#include <numeric>
#include <string>
#include <vector>

#include <common/load_input.h>
#include <common/math.h>

namespace day02 {

class GamePart1 {
public:
  int opponent;
  int myself;

  friend std::istream &operator>>(std::istream &is, GamePart1 &game) {
    std::string opponent_move;
    std::string myself_move;
    is >> opponent_move >> myself_move;

    if (!opponent_move.empty()) {
      game.opponent = toScore(opponent_move);
      game.myself = toScore(myself_move);
    }
    return is;
  }

  static int toScore(const std::string &move) {
    if (move == "A") {
      return 1;
    }
    if (move == "B") {
      return 2;
    }
    if (move == "C") {
      return 3;
    }
    if (move == "X") {
      return 1;
    }
    if (move == "Y") {
      return 2;
    }
    if (move == "Z") {
      return 3;
    }

    throw std::runtime_error("Unknown score");
  }
};

class GamePart2 {
public:
  int opponent;
  int myself;

  friend std::istream &operator>>(std::istream &is, GamePart2 &game) {
    std::string opponent_move;
    std::string desired_outcome;
    is >> opponent_move >> desired_outcome;

    if (!opponent_move.empty()) {
      game.opponent = GamePart1::toScore(opponent_move);
      game.myself = toMove(game.opponent, desired_outcome);
    }
    return is;
  }

  static int toMove(const int opponent_move,
                    const std::string &desired_outcome) {
    // I lose
    // Rock defeats Scissors:  myself = 3, opponent = 1
    // Scissors defeats Paper: myself = 2, opponent = 3
    // Paper defeats Rock.     myself = 1, opponent = 2
    if (desired_outcome == "X") {
      return common::move_into_range(opponent_move - 1, 3, 1, 3);
    }

    // draw
    if (desired_outcome == "Y") {
      return opponent_move;
    }

    // I win
    // Rock defeats Scissors:  myself = 1, opponent = 3
    // Scissors defeats Paper: myself = 3, opponent = 2
    // Paper defeats Rock.     myself = 2, opponent = 1
    if (desired_outcome == "Z") {
      return common::move_into_range(opponent_move + 1, 3, 1, 3);
    }

    throw std::runtime_error("Unknown score");
  }
};

template <class T> int calculateOutcome(const T &game) {
  int outcome = common::positive_modulo(game.myself - game.opponent, 3);
  switch (outcome) {

  // draw
  case 0:
    return 3;

  // I win
  // Rock defeats Scissors:  myself = 1, opponent = 3
  // Scissors defeats Paper: myself = 3, opponent = 2
  // Paper defeats Rock.     myself = 2, opponent = 1
  case 1:
    return 6;

  // I lose
  // Rock defeats Scissors:  myself = 3, opponent = 1
  // Scissors defeats Paper: myself = 2, opponent = 3
  // Paper defeats Rock.     myself = 1, opponent = 2
  case 2:
    return 0;

  default:
    throw std::runtime_error("Unknown outcome");
  }
}

} // namespace day02

int main() {
  {
    // read games
    using day02::GamePart1;
    std::vector<GamePart1> games;
    std::ifstream is("../input/input.txt");
    common::read_lines<GamePart1>(is, std::back_inserter(games));

    // calculate score of own moves
    int score_own_moves = std::accumulate(
        games.cbegin(), games.cend(), 0,
        [](int total, const auto &game) { return total + game.myself; });

    // calculate score of outcomes
    int score_outcomes = std::accumulate(
        games.cbegin(), games.cend(), 0, [](int total, const auto &game) {
          return total + day02::calculateOutcome<GamePart1>(game);
        });

    std::cout << "Part 1: " << score_own_moves + score_outcomes << std::endl;
  }

  {
    // read games
    using day02::GamePart2;
    std::vector<GamePart2> games;
    std::ifstream is("../input/input.txt");
    common::read_lines<GamePart2>(is, std::back_inserter(games));

    // calculate score of own moves
    int score_own_moves = std::accumulate(
        games.cbegin(), games.cend(), 0,
        [](int total, const auto &game) { return total + game.myself; });

    // calculate score of outcomes
    int score_outcomes = std::accumulate(
        games.cbegin(), games.cend(), 0, [](int total, const auto &game) {
          return total + day02::calculateOutcome<GamePart2>(game);
        });

    std::cout << "Part 2: " << score_own_moves + score_outcomes << std::endl;
  }

  std::cout << "done" << std::endl;
}
