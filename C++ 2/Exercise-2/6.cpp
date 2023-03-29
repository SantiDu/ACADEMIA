#include <iostream>
#include <iomanip>

using namespace std;

class Point {
     private:
          int x;
          int y;
     public:
          Point(int x, int y);
          int get_x() const;
          int get_y() const;
};

int main () {
     Point * p_temp = nullptr;
     Point * p_p1 = new Point(1.2, 3.4);
     Point * p_p2 = new Point(6.7, 8.9);
     p_p1->get_x();
     p_p2->get_y();
     p_temp = p_p1;
     p_p1 = p_p2;
     p_p2 = p_temp;
     delete p_p1;
     delete p_p2;
     p_p1 = nullptr;
     p_p2 = nullptr;
     return 0;
}

Point::Point(int x, int y) : x(x), y(y) {}
int Point::get_x() const {return x;}
int Point::get_y() const {return y;}