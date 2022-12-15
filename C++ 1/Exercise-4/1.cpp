#include <iostream>
#include <iomanip>

using namespace std;

int main() {
      cout << setfill('0');
      for (int i = 0; i < 1024; ++i ) {
            cout << setw (4) << i << endl;
      }
      return 0;
}