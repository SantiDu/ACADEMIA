#include <iostream>
#include <iomanip>
#include <sstream>
#include <bitset>

using namespace std;

int main() {
    unsigned int mask = 32;
    cout << bitset<32>(mask) << endl;
    cout << bitset<32>(~mask) << endl;
    unsigned int n = 698;
    cout << bitset<32>(n) << endl;
    cout << bitset<32>(n & ~mask) << endl;
    n &= ~mask;
    return 0;
}