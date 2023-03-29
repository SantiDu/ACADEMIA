#include <iostream>
#include <iomanip>
#include <map>

using namespace std;

class Car {
    private:
        double price;
    public:
        double get_price() const;
        void set_price(double price);
};

int main() {
    map<string, Car> cars_map;
    map<string, Car>::iterator iter;
    iter = cars_map.find("FKLQW1234GKMC");
    if (iter != cars_map.end()) {
        iter->second.set_price(iter->second.get_price() * 1.25);
    }
    return 0;
}