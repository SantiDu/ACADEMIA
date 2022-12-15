#include <iostream>
#include <iomanip>

using namespace std;

int main() {
      double array[] = {10, 3, 19, 56, 8, 22, 15};
      double temp = 0.0;
      double size = sizeof(array) / sizeof(array[0]);

      for (int i = size - 1; i > 0; --i) {
            if (array[i] < array[i - 1]) {
                  temp = array[i];
                  array[i] = array[i - 1];
                  array[i - 1] = temp;
            }
      }

      for (int i = 0; i < size; ++i) {
            cout << array[i] << " ";
      }
      cout << endl;

      return 0;
}