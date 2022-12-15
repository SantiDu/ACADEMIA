#include <iostream>
#include <iomanip>

using namespace std;

int SumOfDigits(int n);

int main() {
      int n = 0;
      int sum = 0;

      cin >> n;

      sum = SumOfDigits(n);

      cout << sum << endl;

      return 0;
}

int SumOfDigits(int n) {
      int sum = 0;
      int digit = 0;

      while (n != 0) {
            digit = n % 10;
            sum += digit;
            n /= 10;
      }

      return sum;
}