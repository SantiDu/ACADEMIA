#include <iostream>
#include <iomanip>

using namespace std;

int Max(int x, int y, int z);

int main () {
     cout << Max(1, 2, 3) << endl;
     cout << Max(1, 3, 2) << endl;
     cout << Max(2, 1, 3) << endl;
     cout << Max(2, 3, 1) << endl;
     cout << Max(3, 1, 2) << endl;
     cout << Max(3, 2, 1) << endl;
     return 0;
}

int Max(int x, int y, int z) {
     return x > y
     ? x > z
       ? x
       : z
     : y > z
       ? y
       : z;
//     return x > y ? (x > z ? x : z) : (y > z ? y : z);
}