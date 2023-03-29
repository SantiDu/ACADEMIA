#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main() {
    ifstream fin("8.txt");
    ofstream fout("out.txt"); 
    string  line;

    if (!fin) {
        cout << "ERROR: Failed to open input file.\n";
        return 1;
    }
    if (!fout) {
        cout << "ERROR: Failed to open output file.\n";
        return 1;
    }

    while (getline(fin, line)) {
        for (auto & c : line) {
            fout << static_cast<char>(toupper(c));
        }
        fout << endl;
    }

    fin.close(); 
    fout.close();

    return 0;
}