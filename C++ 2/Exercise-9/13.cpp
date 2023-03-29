#include <iostream>
#include <iomanip>
#include <map>

using namespace std;

int function(map<int, string> & a_map, int n);

int main() {
    return 0;
}

int function(map<int, string> & a_map, int n) {
    int count = 0;
    int delete_key = 0;
    map<int, string>::iterator iter;
    for (iter = a_map.begin(); iter != a_map.end(); ++iter) {
        if (iter->first < n) {
            delete_key = iter->first;
            a_map.erase(delete_key);
            ++count;
        }
        else {
            break;
        }
    }
    return count;
}

// int  EraseAllSmaller ( std::map <int, string> & my_map, int target ) {
//      int count = 0;

//      for ( std::map <int, string>::iterator iter = my_map.begin ( ); iter != my_map.end (); ) {
//             if ( iter->first < target ) {
//                  iter =  my_map.erase ( iter );
//                    ++count;
//             }
//             else
//                 break;
//       }
//       return count;
// }