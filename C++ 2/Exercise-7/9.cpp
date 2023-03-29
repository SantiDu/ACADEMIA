#include <iostream>
#include <iomanip>

using namespace std;

class Property {
    private:
        double price;
    public:
        bool operator>(const Property & right) const;
};

int main() { 
}

bool Property::operator>(const Property & right) const {
    return price > right.price;
}