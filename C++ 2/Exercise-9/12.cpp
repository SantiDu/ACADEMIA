#include <iostream>
#include <iomanip>
#include <map>

using namespace std;

int main() {
    map<string, double> salesperson_map;
    salesperson_map.insert(pair<string, double>("Jimmy K", 35000.0));
    salesperson_map["Kate N"] = 12570.0;
    return 0;
}