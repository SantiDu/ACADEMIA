#include <iostream>

using namespace std;

int main() {
    const int kNDoubles = 1024;
    double * p_double_list = new double[kNDoubles];
    double * p_double = p_double_list;
    double sum = 0.0;

    for (int i = 0; i < kNDoubles; ++i) {
        *p_double++ = i * 1.99;
    }

    p_double = p_double_list;
    for (int i = 0; i < kNDoubles; ++i) {
        sum += *p_double++;
    }
    cout << sum / kNDoubles << endl;

    delete[] p_double_list;

    return 0;
}