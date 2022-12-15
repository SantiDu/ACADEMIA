#include <iostream>
#include <iomanip>

using namespace std;

int main() {
      int mortgage_term = 0;
      double percent_interest_rate = 0.0;

      if (mortgage_term >= 30) {
            percent_interest_rate = 7.0;
      }
      else if (mortgage_term >= 15 && mortgage_term <= 29) {
            percent_interest_rate = 5.5;
      }
      else if (mortgage_term >= 10 && mortgage_term <= 14) {
            percent_interest_rate = 4.5;
      }
      else {
            percent_interest_rate = 3.5;
      }

      cout << percent_interest_rate << endl;

      return 0;
}