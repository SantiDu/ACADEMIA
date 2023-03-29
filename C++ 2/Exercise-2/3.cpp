#include <iostream>
#include <iomanip>

using namespace std;

int main () {
     int * p_month = nullptr;
     int month = 1;
     p_month = &month;
     *p_month = 11;
     cout << *p_month << endl;
     return 0;
}