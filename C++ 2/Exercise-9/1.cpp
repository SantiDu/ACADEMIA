#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

class Car {
    public:
        void SmogCheck();
};

int main() {
    vector<Car> car_list;
    for (vector<Car>::iterator car_iter = car_list.begin(); car_iter != car_list.end(); ++car_iter) {
        car_iter->SmogCheck();
    }
    return 0;
}