#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void BubbleSort(int arr[], unsigned int size);

int main() {
    unsigned int kNElem = 3;
    int arr[kNElem] = {1, 3, 2};
    BubbleSort(arr, kNElem);
    for (int i = 0; i < kNElem; ++i) {
        cout << arr[i] << endl;
    }
    return 0;
}

void BubbleSort(int arr[], unsigned int size) {
    bool swapped = true;
    int temp = 0;
    int j = 0;

    while (swapped) {
        swapped = false;
        ++j;
        for (int i = 0; i < size - j; ++i) {
            if (arr[i + 1] < arr[i]) {
                temp = arr[i + 1];
                arr[i + 1] = arr[i];
                arr[i] = temp;
                swapped = true;
            }
        }
    }
}
