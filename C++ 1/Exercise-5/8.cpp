#include <iostream>
#include <iomanip>

using namespace std;

bool IsPalindrome(char arr[], int size);

int main() {
      char arr1[] = {'a', 'b', 'a'};
      char arr2[] = {'a', 'b', 'b', 'a'};
      char arr3[] = {'a', 'b', 'c'};
      char arr4[] = {'a', 'b', 'c', 'a'};
      char arr5[] = {};

      cout << IsPalindrome(arr1, 3) << endl;
      cout << IsPalindrome(arr2, 4) << endl;
      cout << IsPalindrome(arr3, 3) << endl; 
      cout << IsPalindrome(arr4, 4) << endl;
      cout << IsPalindrome(arr5, 0) << endl;

      return 0;
}

bool IsPalindrome(char arr[], int size) {
      int pos1 = 0;
      int pos2 = size - 1;
      while (pos2 - pos1 >= 1) {
            if (arr[pos1] != arr[pos2]) {
                  return false;
            }
            else {
                  ++pos1;
                  --pos2;
            }
      }
      return true;
}