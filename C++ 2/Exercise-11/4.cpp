#include <iostream>
#include <iomanip>
#include <sstream>
#include <bitset>

using namespace std;

int main() {
    unsigned int mask = 24;
    cout << bitset<32>(mask) << endl;
    unsigned int n = 366;
    cout << bitset<32>(n) << endl;
    cout << bitset<32>(n & mask) << endl;
    cout << bitset<32>(n & mask >> 3) << endl;
    cout << bitset<32>((n & mask) >> 3) << endl;
    cout << ((n & mask) >> 3) << endl;
    n &= mask;
    return 0;
}