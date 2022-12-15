#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Toy {
    public:
        Toy();
        int a();
        int b();
};

int main() {
    Toy toy;
    const Toy & toy1 = toy;

    toy.a();
    return 0;
}
