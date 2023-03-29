#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main() {
    string buffer;
    string ssn;
    string year;
    int age = 0;
    int n_age_between_25_40 = 0;
    istringstream iss;

    ifstream fin("7.txt");
    ofstream fout("SSN.txt");

    if (!fin) {
        cout << "ERROR: Failed to open input file\n";
        return 1;
    }
    
    if (!fout) {
        cout << "ERROR: Failed to open output file.\n";
        return 1;
    }

    while (getline(fin, buffer, '~')) {
        getline(fin, buffer, '~');
        getline(fin, ssn, '~');  
        getline(fin, buffer, '/');
        getline(fin, buffer, '/');
        getline(fin, year, '\n');

        fout << ssn << endl;
        iss.clear();
        iss.str(year);
        iss >> age; 
        age = 2021 - age;
        if (age >= 25 && age <= 40) {
            ++n_age_between_25_40;
        }
    }
    cout << n_age_between_25_40 << endl;

    fin.close();
    fout.close();

    return 0;
}