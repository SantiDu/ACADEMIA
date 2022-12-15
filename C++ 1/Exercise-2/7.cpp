#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
      float value = 7901.89547f;

      // https://stackoverflow.com/q/45084317/9851286 setprecision without fixed.
      cout << setw(13) << setfill('0') << fixed << setprecision(4) << value << endl;

      return 0;
}
