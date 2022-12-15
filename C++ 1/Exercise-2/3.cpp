#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

double CelsiousToFahrenheit(double degree_in_Celsious);

int main() {
      cout << CelsiousToFahrenheit(-40) << endl;
      return 0;
}

double CelsiousToFahrenheit(double degree_in_Celsious) {
      return degree_in_Celsious * 9 / 5 + 32;
}