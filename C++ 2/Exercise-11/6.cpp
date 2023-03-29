#include <iostream>
#include <iomanip>
#include <sstream>
#include <bitset>

using namespace std;

int main() {
    unsigned int n = 4;
    cout << bitset<32>(n) << endl;
    unsigned int m = 400;
    cout << bitset<32>(m) << endl;
    cout << bitset<32>(m | n) << endl;
    m |= n;
    return 0;
}