#include <iostream>
#include <iomanip>

using namespace std;

int main() {
      int n = 0;
      int product = 1;

      cout << "Input n: ";
      cin >> n;

      while (n != 0) {
            product *= n;
            --n;
      }

      cout << product << endl;

      return 0;
}