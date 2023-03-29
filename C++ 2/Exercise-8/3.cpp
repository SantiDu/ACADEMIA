#include <iostream>
#include <iomanip>

using namespace std;

template <typename T>
int function(T array[], T target, int size);

int main() {
    int array[3] = {1, 2, 2};
    cout << function(array, 2, 3) << endl;
    return 0;
}

template <typename T>
int function(T array[], T target, int size) {
    int count = 0;
    T * p_t = array;
    for (int i = 0; i < size; ++i) {
        if (*p_t == target) {
            ++count;
        }
        ++p_t;
    }
    return count;
}