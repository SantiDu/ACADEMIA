#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
      double value = 23.59821;

      cout << fixed;
      cout << setprecision(3);
      // cout << right;
      cout << setw(10) << value << endl;

      return 0;
}
