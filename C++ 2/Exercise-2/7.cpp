#include <iostream>
#include <iomanip>

using namespace std;

class Memory {
     public:
          Memory();
          ~Memory();     
};

int main () {
     Memory mem;  // ctor
     Memory * p_memory = new Memory();  // ctor
     delete p_memory;  // dtor
     return 0;  // dtor
}

Memory::Memory() {cout << "Memory ctor\n";}
Memory::~Memory() {cout << "Memory dtor\n";}  