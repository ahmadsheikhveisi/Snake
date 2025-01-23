/* COPYRIGHT
*/

#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <iostream>
#include <list>
#include <unordered_map>

#include "vertebra.hpp"

namespace snake {

enum class Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class Snake {
 public:
    explicit Snake(Direction direction, int x, int y) : direction_{direction} {
        vertebrae_.emplace_back(Vertebra(x, y));
        auto [dx, dy] = direction_map_.at(direction_);
        vertebrae_.emplace_back(Vertebra(x + (-1 * dx), y + (-1 * dy)));
        vertebrae_.emplace_back(Vertebra(x + (-2 * dx), y + (-2 * dy)));
    }

    void Crawl() {
        Feed();
        vertebrae_.pop_back();
    }

    void Feed() {
        auto [dx, dy] = direction_map_.at(direction_);
        auto [x, y] = std::make_pair(vertebrae_.front().GetX() + dx, vertebrae_.front().GetY() + dy);
        vertebrae_.emplace_front(Vertebra(x, y));
    }

    bool IsEatingItself() {
        auto head = vertebrae_.front();
        for (auto it = std::next(begin(vertebrae_)); it != vertebrae_.end(); ++it) {
            if (head == *it) {
                return true;
            }
        }
        return false;
    }

    void ChangeDirection(Direction direction) {
        direction_ = direction;
    }

    void Print() {
        for (auto& vertebra : vertebrae_) {
            vertebra.Print();
        }
    }

 private:
    std::list<Vertebra> vertebrae_;
    Direction direction_;
    const std::unordered_map<Direction, std::pair<int, int>> direction_map_ {{
        {Direction::UP, {0, 1}},
        {Direction::DOWN, {0, -1}},
        {Direction::LEFT, {-1, 0}},
        {Direction::RIGHT, {1, 0}}
    }};
};

}  // namespace snake
#endif // SNAKE_HPP
