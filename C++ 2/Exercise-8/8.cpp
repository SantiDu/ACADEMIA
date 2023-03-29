#include <iostream>
#include <iomanip>

using namespace std;

template <class T>
class Base {

};

template <class T, class V>
class Derived : public B<T> {

};

int main() {
    return 0;
}