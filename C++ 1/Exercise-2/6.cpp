#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
      int x = 10;
      string message = "CS 2A";
      float value = 12.8967f;

      cout << fixed;
      cout << setw(5) << setfill('0') << x << endl;
      cout << setw(10) << setfill('-') << message << endl;
      cout << setw(8) << setfill('0') << setprecision(2) << value << endl;

      return 0;
}
