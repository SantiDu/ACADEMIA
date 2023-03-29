#include <iostream>

using namespace std;

int main() {
    const int kNInt = 128;
    int * const p_int_list = new int[kNInt];

    int * p_int = p_int_list;
    for (int i = 0; i < kNInt; ++i) {
        *p_int++ = 100;
    }

    delete[] p_int_list;

    return 0;
}