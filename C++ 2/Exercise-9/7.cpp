#include <iostream>
#include <iomanip>
#include <vector>
#include <math.h>

using namespace std;

int main() {
    int sum = 0;
    vector<int> * p_ints = new vector<int>();
    for (int i = 0; i < 6; ++i) {
        p_ints->push_back(pow(2, i));
    }
    vector<int>::iterator iter;
    for (iter = p_ints->begin(); iter != p_ints->end(); ++iter) {
        sum += *iter;
    }
    cout << sum << endl;
    p_ints->clear();
    delete p_ints;
    return 0;
}