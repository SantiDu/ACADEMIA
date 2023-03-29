#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
    int number = 0;
    int count = 0;
    int count_64 = 0;
    double sum = 0.0;
    vector<int> int_list;
    const int kTarget = 64;
    for (;;) {
        cout << "Enter a positive integer (negative to stop): ";
        cin >> number;
        if (number < 0) {
            break;
        }
        else {
            int_list.push_back(number);
        }
    }
    vector<int>::iterator iter;
    for (iter = int_list.begin(); iter != int_list.end(); ++iter) {
        sum += *iter;
        ++count;
        if (*iter == kTarget) {
            ++count_64;
        }
    }
    cout << "Average: " << sum / count << endl;
    cout << "Number of 64: " << count_64 << endl;
    return 0;
}