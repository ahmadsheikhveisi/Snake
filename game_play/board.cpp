/* COPYRIGHT
*/

#include "board.hpp"

#include <chrono>
#include <memory>
#include <random>
#include <vector>

#include "snake.hpp"

namespace game_play {


Board::Board(Point point) : point_{point} {
    snake_ = std::make_unique<snake::Snake>(snake::Direction::RIGHT, point_.x / 2, point_.y / 2);
    GenerateFood();
}

bool Board::Update() {
    snake_->Crawl();
    if (Collisions()) {
        return false;
    }
    auto head = snake_->GetHead();
    if ((head.GetX() == food_.x) && (head.GetY() == food_.y)) {
        snake_->Feed();
        GenerateFood();
    }
    return true;
}

bool Board::Collisions() {
   auto head = snake_->GetHead();
    if (head.GetX() < 0 || head.GetX() >= point_.x || head.GetY() < 0 || head.GetY() >= point_.y) {
        return true;
    }
    return snake_->IsEatingItself();
}

void Board::GenerateFood() {
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 gen(seed);
    std::uniform_int_distribution<> dis_x(0, point_.x - 1);
    std::uniform_int_distribution<> dis_y(0, point_.y - 1);
    food_ = {dis_x(gen), dis_y(gen)};
}

} // namespace game_play