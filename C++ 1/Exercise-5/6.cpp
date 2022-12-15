#include <iostream>
#include <iomanip>

using namespace std;

bool TwoArraysSame(int array1[], int array2[], int size);

int main() {
      int array1[] = {1, 2, 3, 4};
      int array2[] = {1, 2, 3, 4};
      int size = sizeof(array1) / sizeof(array1[0]);

      if (TwoArraysSame(array1, array2, size)) {
            cout << "Same" << endl;
      }
      else {
            cout << "Diff" << endl;
      }

      return 0;
}

bool TwoArraysSame(int array1[], int array2[], int size) {
      for (int i = 0; i < size; ++i) {
            if (array1[i] != array2[i]) {
                  return false;
            }
      }
      return true;
}