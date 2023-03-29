#include <iostream>
#include <iomanip>

using namespace std;

class Point {
   public:
      double get_x() const;
      double get_y() const;
};

void DisplayPositivePoints(Point points[], int size);

int main () {
     return 0;
}


void DisplayPositivePoints(Point points[], int size) {
     double x = 0.0;
     double y = 0.0;
     for (int i = 0; i < size; ++i) {
          x = points[i].get_x();
          y = points[i].get_y();
          if (x > 0 && y > 0) {
               cout << x << ", " << y << endl;
          }
     }
}

