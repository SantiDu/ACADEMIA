#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

class Point {
    private:
        double x;
        double y;
    public:
        Point(double x, double y);
        double get_x() const;
        double get_y() const;
};

int main() {
    vector<Point *> point_pointers;
    point_pointers.push_back(new Point(1, 2));
    point_pointers.push_back(new Point(3, 4));
    point_pointers.push_back(new Point(2, 4));
    point_pointers.push_back(new Point(1.3, 7.2));
    point_pointers.push_back(new Point(5.6, 9.1));
    vector<Point *>::iterator iter = point_pointers.begin();
    while (iter != point_pointers.end()) {
        if ((*iter)->get_x() == 1.3 && (*iter)->get_y() == 7.2) {
            delete *iter;
            iter = point_pointers.erase(iter);
        }
        else {
            ++iter;
        }
    }
    for (iter = point_pointers.begin(); iter != point_pointers.end(); ++iter) {
        delete *iter;
    }
    point_pointers.clear();    

    return 0;
}

Point::Point(double x, double y) : x(x), y(y) {}
double Point::get_x() const {return x;}
double Point::get_y() const {return y;}