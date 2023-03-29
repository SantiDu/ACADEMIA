#include <iostream>
#include <iomanip>

using namespace std;

int main () {
     const int kNArray = 3;
     // int array[kNArray] = {0};
     int array[kNArray] = {2, 1, 3};
     int smallest = array[0];
     for (int i = 0; i < kNArray; ++i) {
          if (smallest > array[i]) {
               smallest = array[i];
          }
     }
     cout << smallest << endl;
     return 0;
}