#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
      const double kHourlyFee = 3.5;
      const double kMinutelyFee = 0.05;
      int total_minutes = 0;
      int hours = 0;
      int minutes = 0;
      double fee = 0.0;

      cout << "Input total minutes:";
      cin >> total_minutes;

      hours = total_minutes / 60;
      minutes = total_minutes % 60;
      fee = hours * kHourlyFee + minutes * kMinutelyFee;

      cout << fee;

      return 0;
}
