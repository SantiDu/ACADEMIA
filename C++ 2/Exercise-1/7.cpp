#include <iostream>
#include <iomanip>

using namespace std;

bool TwoArrays(int array1[], int array2[], int size);

int main () {
     const int kArraySize = 3;
     int array1[kArraySize] = {1, 2, 3};
     int array2[kArraySize] = {1, 2, 3};
     cout << TwoArrays(array1, array2, kArraySize) << endl;
     return 0;
}

bool TwoArrays(int array1[], int array2[], int size) {
     for (int i = 0; i < size; ++i) {
          if (array1[i] != array2[i]) {
               return false;
          }
     }
     return true;
}