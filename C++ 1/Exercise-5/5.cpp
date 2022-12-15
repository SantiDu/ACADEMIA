#include <iostream>
#include <iomanip>

using namespace std;

int main() {
      int array[] = {1, 3, 4, 10, 15, 100};
      int size = sizeof(array) / sizeof(array[0]);
      int temp = 0;

      for (int i = 0; i <= size / 2; ++i) {
            temp = array[i];
            array[i] = array[size - (i + 1)];
            array[size - (i + 1)] = temp;
      }

      for (int i = 0; i < size; ++i) {
            cout << array[i] << " ";
      }
      cout << endl;

      return 0;
}