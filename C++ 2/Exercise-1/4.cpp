#include <iostream>
#include <iomanip>

using namespace std;

int main () {
     string protocol = "https";
     string domain = "foothill.edu";
     string department = "cs";
     string url = protocol + "://" + domain + "/" + department;
     cout << url << endl; 

     int idx = 0;
     int new_idx = -1;
     for (int i = 0; i < 3; ++i) {
          idx = new_idx;
          new_idx = url.find('/', idx + 1);
          cout << url.substr(idx + 1, new_idx - (idx + 1)) << endl;
     }
     return 0;
}