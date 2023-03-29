#include <iostream>
#include <iomanip>
#include <map>
#include <vector>
#include <string>

using namespace std;

using year = int;
using make = string;

class Vehicle {

};

class Car : public Vehicle {

};

int main() {
    map<year, map<make, vector<Car>>> inventory;
    return 0;
}