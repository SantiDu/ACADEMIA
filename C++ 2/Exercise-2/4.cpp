#include <iostream>
#include <iomanip>

using namespace std;

int main () {
     double * p_number = new double(0.0);
     *p_number = 99.95;
     cout << *p_number << endl;
     delete p_number;
     p_number = nullptr;
     return 0;
}