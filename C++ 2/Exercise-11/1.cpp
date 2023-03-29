#include <iostream>
#include <iomanip>
#include <sstream>
#include <bitset>
#include <climits>

using namespace std;

int main() {
    unsigned int n = 0x111;
    cout << dec << n << endl;
    cout << "0x" << hex << n << endl;
    cout << bitset<sizeof(int) * CHAR_BIT>(n) << endl;

    cout << endl;

    unsigned int m = 273;
    ostringstream oss;
    oss << "0x" << hex << m << endl;
    cout << oss.str();
    bitset<32> bit_data(m);
    oss.str("");
    oss.clear();
    oss << bit_data << endl;
    cout << oss.str();
    return 0;
}