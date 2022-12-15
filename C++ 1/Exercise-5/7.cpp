#include <iostream>
#include <iomanip>

using namespace std;

int main() {
      int array[] = {1, 2, 3, 4};
      int size = sizeof(array) / sizeof(array[0]);
      int temp = 0;
      int pos = 0;

      for (int i = 0; i < size / 2; ++i) {
            pos = size / 2 + i;
            temp = array[i];
            array[i] = array[pos];
            array[pos] = temp;
      }

      for (int i = 0; i < size; ++i) {
            cout << array[i] << " ";
      }
      cout << endl;

      return 0;
}