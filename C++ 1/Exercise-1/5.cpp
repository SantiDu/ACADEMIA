#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main ( )  {
      int year = 2021;
      int next_year = 2022;

      cout << year << endl;
      int temp;
      temp = year;
      year = next_year;
      next_year = temp;

      cout << year << endl;
      cout << next_year << endl;
      
      return 0;
}
