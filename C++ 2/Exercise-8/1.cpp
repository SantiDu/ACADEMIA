#include <iostream>
#include <iomanip>

using namespace std;

class Mouse {
  private:
     int mode;   // 0: wiring 1: wireless.
     string brand;
  public:
    Mouse();
    Mouse(int mode, string brand);
    friend ostream & operator<<(ostream & os, const Mouse & mouse);
};

class Laptop {
  private:
    double size;
    Mouse * p_mouse;   // dynamic Mouse object.
  public:
    Laptop(double size, Mouse * p_mouse);
    Laptop(const Laptop & other);
    const Laptop & operator=(const Laptop & right);
    friend ostream & operator<<(ostream & os, const Laptop & laptop);
};

int main() {
    Laptop laptop = Laptop(2.2, new Mouse(3, "AK"));
    cout << laptop << endl;
    return 0;
}

Mouse::Mouse() {}
Mouse::Mouse(int mode, string brand) : mode(mode), brand(brand) {}
ostream & operator<<(ostream & os, const Mouse & mouse) {
    os << "mode: " << mouse.mode << endl;
    os << "brand: " << mouse.brand << endl;
    return os;
}

Laptop::Laptop(double size, Mouse * p_mouse) : size(size), p_mouse(p_mouse) {}
Laptop::Laptop(const Laptop & other) : size(other.size), p_mouse(new Mouse(*p_mouse)) {}
//     p_mouse = new Mouse();
//     *p_mouse = *(other.p_mouse);
// }
const Laptop & Laptop::operator=(const Laptop & right) {
    // check for self-assignment
    if (this == &right) {
        return *this;
    }
    // clone none pointer members
    size = right.size;
    // clone pointer members
    delete p_mouse;
    p_mouse = new Mouse();
    *p_mouse = *(right.p_mouse);
    // return
    return *this;
}
ostream & operator<<(ostream & os, const Laptop & laptop) {
    os << "size: " << laptop.size << endl;
    os << "Mouse: " << endl;
    os << *(laptop.p_mouse) << endl;
    return os;
}