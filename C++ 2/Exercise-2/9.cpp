#include <iostream>
#include <iomanip>

using namespace std;

class Point {

}; 

int main () {
     Point * p_point = nullptr;
     Point p1;
     Point * const kp_point = &p1;
     const Point * p_kPoint = nullptr;
     Point p2;  // I wrote const Point p2 initially, but this is ok.
     const Point * const kp_kPoint = &p2;
     return 0;
}