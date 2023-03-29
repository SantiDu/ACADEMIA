#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
    vector<int> int_list = {1, 2, 3};

    int temp = *(int_list.begin());
    *(int_list.begin()) = *(int_list.end() - 1);
    *(int_list.end() - 1) = temp;
    for (auto & e : int_list) {
        cout << e << endl;
    }
    return 0;
}