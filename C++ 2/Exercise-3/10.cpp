#include <iostream>
#include <fstream>

using namespace std;

int SearchFile(string f_path, string patter);

int main() {
    cout << SearchFile("10.txt", "food") << endl;
    return 0;
}

int SearchFile(string f_path, string pattern) {
    ifstream fin(f_path);
    string line;
    int line_number = 0;

    if (!fin) {
        cout << "ERROR: Failed to open input file." << endl;
        return 1;
    }

    while (getline(fin, line)) {
        ++line_number;
        if (line.find(pattern) != string::npos) {
            return line_number;
        }
    }

    fin.close();

    return -1;
}