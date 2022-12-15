#include <iostream>
#include <iomanip>

using namespace std;

int main() {
      for (int i = 1; i < 6; ++i) {
            int n = 1;
            for (int j = 0; j < i; ++j) {
                  cout << n + j << " "; 
            }
            cout << endl;
      }
      return 0;
}