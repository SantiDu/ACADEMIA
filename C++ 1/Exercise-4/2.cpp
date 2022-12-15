#include <iostream>
#include <iomanip>

using namespace std;

int main() {
      cout << setfill('0');
      int i = 0;

      while (i < 1024) {
            cout << setw(4) << i << endl;
            ++i;
      }
      return 0;
}