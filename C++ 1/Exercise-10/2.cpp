#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    int * p_i = nullptr;
    int month = 12;
    p_i = &month;
    *p_i = 1;
    cout << month;
    return 0;
}