#include <iostream>
#include <iomanip>
#include <vector>

using std::cout;
using std::endl;

int main() {
    std::vector<int> v = {1,2,3,4,5,6};   // this syntax works only if your compiler supports C++ 11 or later.

    std::vector<int>::iterator iter = v.begin();
    ++iter;
    ++iter;
    ++iter;

    cout << *iter << endl;  // 4

    return 0;
}