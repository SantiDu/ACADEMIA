#include <iostream>
#include <iomanip>

using namespace std;

int main() {
      // no output

      int score = 84 ;

      if (score > 90)
            cout << "Congrats! You got an A. " ;
            cout << "It's time to enjoy your vacation.";

      score = 75;

      if (score > 80)
            cout << "Congrats! You got an B. " ;
      else
            cout << "Satisfactory results. Keep working on it!";

      return 0;
}