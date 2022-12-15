#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

int main() {
      int integers[32] = {0};
      integers[2] = 8;
      integers[3] = -1;
      double min = numeric_limits<double>::infinity();
      double max = -numeric_limits<double>::infinity();

      for (int i = 0; i < 32; ++i) {
            if (integers[i] < min) {
                  min = integers[i];
            }
            if (integers[i] > max) {
                  max = integers[i];
            }
      }
      
      cout << "min: " << min << endl;
      cout << "max: " << max << endl;

      return 0;
}