#include <iostream>
#include <iomanip>

using namespace std;

int main() {
      int age = 18;
      float admission_price = 15.0f;     

      cout << "Enter an age: ";
      cin >> age;

      switch (age) {
            case 0:
            case 1:
            case 2:
            case 3 ... 12:
                  admission_price = 5.0;      // kid price
                  break;
            case 13 ... 17:
                  admission_price = 10.0;     // teen price
                  break;
            case 18:
                  admission_price = 15.0;      // HS graduation price
                  break;
            case 19 ... 54:
                  admission_price =  17.0;   // adult price
                  break;
            default:
                  admission_price =  10.0;   // senior price
      }

      cout << admission_price << endl;

      return 0;
}