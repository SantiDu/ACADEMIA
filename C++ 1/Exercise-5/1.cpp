#include <iostream>
#include <iomanip>

using namespace std;

int main() {
      int integers[32] = {0};
      // const int kSize = 32;
      // int values [kSize];

      // for ( int i = 0; i < kSize; ++i ) {
      // values[i] = 0;
      // }
      
      int count = 0;
      for (int i = 0; i < 32; ++i) {
            if (integers[i] == 0) {
                  ++count;
            }
      }

      cout << count << endl;

      return 0;
}