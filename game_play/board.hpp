/* COPYRIGHT
*/

#ifndef GAME_PLAY_BOARD_HPP
#define GAME_PLAY_BOARD_HPP

#include <memory>
#include <vector>

#include "snake.hpp"

namespace game_play {

struct Point {
    int x;
    int y;
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

class Board {
 public:
    explicit Board(Point point);
    bool Update();
 private:
    Point point_;
    std::unique_ptr<snake::Snake> snake_;
    Point food_;

    bool Collisions();
    void GenerateFood();

};

} // namespace game_play
#endif // GAME_PLAY_BOARD_HPP
