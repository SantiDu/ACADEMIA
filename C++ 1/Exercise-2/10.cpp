#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
      int value_1 = 12;
      int value_2 = 785;
      int value_3 = 89756;

      cout << setfill ('#');
      cout << setw(5) << value_1 << endl;  // ###12 
      cout << value_2 << endl;  // 785
      cout << value_3 << endl;  // 89756

      return 0;
}
