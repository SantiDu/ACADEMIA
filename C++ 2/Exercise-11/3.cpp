#include <iostream>
#include <iomanip>
#include <sstream>
#include <bitset>

using namespace std;

int main() {
    unsigned int n = 0x4;
    cout << bitset<32>(n) << endl;
    return 0;
}