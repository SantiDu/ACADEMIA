#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream binary_fin("a.out", ios::in | ios::binary); 
    ofstream binary_fout("b.out", ios::out | ios::binary);
    char byte = '\0';

    while (binary_fin.get(byte)) {
            binary_fout.put(byte);
    }

    binary_fin.close();
    binary_fout.close();

    return 0;
}