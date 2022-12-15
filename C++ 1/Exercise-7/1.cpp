#include <iostream>
#include <iomanip>

using namespace std;

class Rectangle {
    private:
        double width;
        double length;
    private:
        static double DEFAULT_WIDTH;
        static double DEFAULT_LENGTH;
    public:
        Rectangle();
        Rectangle(double width, double height);
        ~Rectangle();
        double get_width() const;
        double get_length() const;
        void set_width(double width);
        void set_length(double width);
        double Area() const;
        double Perimeter() const;
    public:
        static double get_default_width();
        static double get_default_length();
        static void set_default_width(double width);
        static void set_default_length(double width);
};

int main() {
    Rectangle rec1;
    Rectangle rec2(90.0, 60.0);
    rec1 = rec2;

    return 0;
}

double Rectangle::DEFAULT_WIDTH = 0.0;
double Rectangle::DEFAULT_LENGTH = 0.0;

Rectangle::Rectangle() : width(Rectangle::DEFAULT_WIDTH),length(Rectangle::DEFAULT_LENGTH) {}
Rectangle::Rectangle(double width, double length) : width(width),length(length) {}
Rectangle::~Rectangle() {};

double Rectangle::get_default_length() {
    return Rectangle::DEFAULT_LENGTH;
}

double Rectangle::get_default_width() {
    return Rectangle::DEFAULT_WIDTH;
}

void Rectangle::set_default_width(double width) {
    Rectangle::DEFAULT_WIDTH = width;
}

void Rectangle::set_default_length(double length) {
    Rectangle::DEFAULT_LENGTH = length;
}

double Rectangle::get_length() const {
    return length;
}

double Rectangle::get_width() const {
    return width;
}

void Rectangle::set_length(double new_length) {
    length = new_length;
}

void Rectangle::set_width(double new_width) {
    width = new_width;
}

double Rectangle::Area() const {
    return width * length;
}

double Rectangle::Perimeter() const {
    return (width + length) * 2;
}