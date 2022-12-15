#include <iostream>
#include <iomanip>

using namespace std;

int main() {
      char traffic_light = '\0';

      cin >> traffic_light;

      switch (traffic_light) {
            case 'G':
                  cout << "You're good to go" << endl;
                  break;
            case 'R':
                  cout << "Stop immediately" << endl;
                  break;
            case 'Y':
                  cout << "Slow down!" << endl;
                  break;
            default:
                  cout << "Unrecognized traffic light signal!" << endl; 
      }

      return 0;
}