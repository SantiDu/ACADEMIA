#include <iostream>
#include <iomanip>

using namespace std;

int main () {
     int  day = 21;
     int  month = 9;

     int  *  p1 = NULL;
     int  *  p2 = NULL;
     int  *  p3 = NULL;

     p1 = &day;  // *p1 = 21
     p2 = &month;  // *p2 = 9

     p3 = p1;  // *p3 = 21
     p1 = p2;  // *p1 = 9
     p3 = p2;  // *p3 = 9
     p1 = NULL;
     return 0;
}