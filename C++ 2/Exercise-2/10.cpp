#include <iostream>
#include <iomanip>

using namespace std;

int main () {
     int scores [32] = { 0 };
     int * p_score = scores;
     for ( int i = 0; i < 32; ++i ) {
          *p_score = i;
          ++p_score;
     }

     return 0;
}