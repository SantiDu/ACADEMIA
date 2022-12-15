#include <iostream>
#include <iomanip>

using namespace std;

class Rectangle {
    private:
        double width;
        double length;
    public:
        Rectangle();
        Rectangle(double width, double height);
};

int main() {
    Rectangle rec1;
    Rectangle rec2(90.0, 60.0);
    rec1 = rec2;

    return 0;
}

Rectangle::Rectangle():width(0.0),length(0.0){}

Rectangle::Rectangle(double width, double length):width(width),length(length){}