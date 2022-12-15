#include <iostream>
#include <iomanip>

using namespace std;

int main() {
      int i = 0;

      do {
            ++i;
            cout << i << endl;
            cout << "\tMENU" << endl;
            cout << "1. Open account" << endl;
            cout << "2. Update account" << endl;
            cout << "3. Cancel account" << endl;
            cout << "4. Quit" << endl;
      }
      while (i < 10);

      return 0;
}