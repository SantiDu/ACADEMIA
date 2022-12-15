#include <iostream>
#include <iomanip>

using namespace std;

int main() {
      int gpas[32] = {0};
      double sum = 0.0;

      for (int i = 0; i < 32; ++i) {
            sum += gpas[i];
      }

      cout << sum / 32 << endl;

      return 0;
}