#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void DisplayArr(int arr[], unsigned int pos);

int main() {
    unsigned int kNElem = 6;
    int arr[kNElem] = {1, 2, 3, 4, 5, 6};
    DisplayArr(arr, kNElem - 1);
    return 0;
}

void DisplayArr(int arr[], unsigned int pos) {
    cout << "Current elem: " << arr[pos] << endl;
    if (pos == 0) {
        return;
    }
    else {
        DisplayArr(arr, pos - 1);
    }
}
