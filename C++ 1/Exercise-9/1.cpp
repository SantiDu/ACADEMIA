#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int factorial(unsigned int n, unsigned long long product);

int main() {
    cout << factorial(0, 1) << endl;
    return 0;
}

int factorial(unsigned int n, unsigned long long product) {
    switch (n) {
        case 0:
        case 1:
            return product;
        default:
            return factorial(n - 1, n * product);
    }
}