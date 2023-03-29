#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

void function(vector<int> & source, vector<int> & destination);

int main() {
    return 0;
}

void function(vector<int> & source, vector<int> & destination) {
    destination.clear();
    for (vector<int>::iterator iter = source.begin(); iter != source.end(); ++iter) {
        destination.push_back(*iter);
    }
}