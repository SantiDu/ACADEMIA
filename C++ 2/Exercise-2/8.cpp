#include <iostream>
#include <iomanip>

using namespace std;

class Point {
     private:
          int x;
          int y;
     public:
          int get_x() const;
          int get_y() const;
          void Draw() const;
};

int main () {
     const int kArrayLength = 1024;
     Point * p_point_list = new Point[kArrayLength];
     Point * p_point = nullptr;
     for (p_point = p_point_list; p_point < &p_point_list[1024];  p_point++) {
          p_point->Draw();
     }  
     // p_point = point_list;
     // for (int i = 0; i < 1024; ++i) {
     //      p_point->Draw();
     //      ++p_point;
     // }
     delete[] p_point_list;
     return 0;
}

int Point::get_x() const {return x;}
int Point::get_y() const {return y;}