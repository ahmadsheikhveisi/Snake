/* COPYRIGHT
*/

#ifndef VERTEBRA_HPP
#define VERTEBRA_HPP

#include <iostream>

namespace snake {
class Vertebra {
 public:
    Vertebra() : x_{0}, y_{0} {};
    Vertebra(int x, int y): x_{x}, y_{y} {};

    int GetX() { return x_; }
    int GetY() { return y_; }
    void SetX(int x) { x_ = x; }
    void SetY(int y) { y_ = y; }
    void SetXY(int x, int y) { x_ = x; y_ = y; }
    void Print() {
        std::cout << "Vertebra: x = " << x_ << ", y = " << y_ << std::endl;
    }

    bool operator==(const Vertebra& other) const {
        return x_ == other.x_ && y_ == other.y_;
    }
 private:
    int x_;
    int y_;
};
}  // namespace snake
#endif // VERTEBRA_HPP
