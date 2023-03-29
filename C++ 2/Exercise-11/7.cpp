#include <iostream>
#include <iomanip>
#include <sstream>
#include <bitset>

using namespace std;

int main() {
    unsigned int n = 2 + 4 + 8;
    cout << bitset<32>(n) << endl;
    unsigned int m = 66;
    cout << bitset<32>(m) << endl;
    cout << bitset<32>(m | n) << endl;
    cout << (m | n) << endl;
    m |= n;
    return 0;
}