#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

class Laptop {
    public:
        bool IsDefective() const;
};

vector<Laptop> & function(const vector<Laptop> & laptops, vector<Laptop> & defected_laptops);

int main() {
    vector<Laptop> laptops;
    vector<Laptop> defected_laptops;

    return 0;
}

vector<Laptop> & function(const vector<Laptop> & laptops, vector<Laptop> & defected_laptops) {
    vector<Laptop>::const_iterator iter;
    for (iter = laptops.begin(); iter != laptops.end(); ++iter) {
        if (iter->IsDefective()) {
            defected_laptops.push_back(*iter);
        }
    }
    return defected_laptops;
}