#include <iostream>
#include <iomanip>
#include <map>

using namespace std;

class City {
    public:
        int get_population() const;
};

int main() {
    map<string, City> city_map;
    map<string, City>::iterator iter;
    for (iter = city_map.begin(); iter != city_map.end(); ++iter) {
        if (iter->second.get_population() < 2000000) {
            cout << iter->first << endl;
        }
    }
    return 0;
}