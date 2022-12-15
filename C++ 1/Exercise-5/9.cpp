#include <iostream>
#include <iomanip>
using namespace std;
// function declaration
void swap ( int &num1, int &num2 );

// main function
int main ( ) {
  int first_number = 0;
  int second_number = 0;

  cout << "Enter the first integer: ";
  cin >> first_number;
  cout << "Enter the second integer: ";
  cin >> second_number;

  cout << "Before swapping:  first = " << first_number << ",  second = " << second_number << endl;  
  // swap now
  swap ( first_number, second_number );
  cout << "Adter swapping:  first = " << first_number << ",  second = " << second_number << endl;  

  return 0;
}

// function definition
void swap ( int &num1, int &num2 ) {
   int  temp = 0;

   temp = num1;
   num1 = num2;
   num2 = temp;
}