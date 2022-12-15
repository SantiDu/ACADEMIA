#include <iostream>
#include <iomanip>

using namespace std;

int MaxAmongThree(int a, int b, int c);

int main() {
      int a = 0;
      int b = 0;
      int c = 0;

      cin >> a >> b >> c;
      cout << "The largest is: " << MaxAmongThree(a, b, c) << endl;

      return 0;
}

int MaxAmongThree(int a, int b, int c) {
      int max = 0;

      (a > b) ? (max = a) : (max = b);
      (max > c) ? : (max = c); 

      return max;
}

