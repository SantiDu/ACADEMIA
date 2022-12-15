#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void ExtractDigit(int number);
void ExtractTime(int total_second);

int main() {
      cout << endl;
      ExtractDigit(7145) ;
      cout << endl;
      ExtractTime(100000);
      return 0;
}

void ExtractDigit(int number) {
      int thousands = 0;
      int hundres = 0;
      int tens = 0;

      thousands = number / 1000;
      number %= 1000;
      hundres = number / 100;
      number %= 100;
      tens = number / 10;
      number %= 10;

      cout << thousands << endl;
      cout << hundres << endl;
      cout << tens << endl;
      cout << number << endl;
}

void ExtractTime(int total_second) {
      int days = 0;
      int hours = 0;
      int minutes = 0;

      days = total_second / (3600 * 24);
      total_second %= 3600 * 24;
      hours = total_second / 3600;
      total_second %= 3600;
      minutes = total_second / 60;
      total_second %= 60;

      cout << hours << endl;
      cout << minutes << endl;
      cout << total_second << endl;
}