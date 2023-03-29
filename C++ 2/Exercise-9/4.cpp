#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

void function(vector<int> & ints, int value);

int main() {
    vector<int> ints = {1,2,3};
    function(ints, 3);
    for (auto & e : ints) {
        cout << e << endl;
    }
    return 0;
}

void function(vector<int> & ints, int value) {
    vector<int>::iterator iter = ints.begin();
    while (iter != ints.end()) {
    // for (; iter != ints.end();) {
        if (value == *iter) {
            iter = ints.erase(iter);
        }
        else {
            ++iter;
        }
    }
}