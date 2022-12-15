//============================================================================
// File Name   : main.cpp
// Author      : Jinrui Du
// Copyright   : Copyright 2022 Jinrui Du
// Description : This program does what users choose to do from a menu.
// Disclaimer  : This is assignment 3.
// Revision History:
// Date              Version     Change ID         Author             Comment
// 31-10-22          1.0            001           Jinrui Du        Initial creation
//============================================================================

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;

bool IsArmstrongNumber(int n);

int main() {
    char user_choice = '\0';
    int integer = 0;
    int sum = 0; 
    int year = 0;
    int count5 = 0;
    int pos = 0;
    int count = 0;
    string text;

    do {
        cout << "***********************************" << endl;
        cout << "*            FUN MENU             *" << endl;
        cout << "***********************************" << endl;
        cout << "          <S>um of natural integers" << endl;
        cout << "          <L>eap year check        " << endl;
        cout << "          <C>ount vowels           " << endl;
        cout << "          <P>rint Amstrong numbers " << endl;
        cout << "          <E>xit                   " << endl;

        cout << "Please select from the menu: ";
        cin >> user_choice;

        switch (user_choice) {
            case 'S':
            case 's':
                sum = 0;
                cout << "Please enter an integer: ";
                cin >> integer;

                if (integer < 0) {
                    cout << "Error: can't calculate the sum because the integer is negative!" << endl;
                }
                else {
                    for (int i = 1; i <= integer; ++i) {
                        sum += i;
                    }
                    cout << "The sum from 1 to " << integer << " is: " << sum << endl;
                }

                break;
            case 'L':
            case 'l':
                cout << "Please enter a year: ";
                cin >> year;

                if ((year % 4 != 0 || year % 100 == 0) && year % 400 != 0) {
                    cout << year << " is not a leap year" << endl;
                }
                else {
                    cout << year << " is a leap year" << endl;
                }

                break;
            case 'C':
            case 'c':
                text = "";
                cin.ignore();
                cout << "Please enter a text: ";
                getline(cin, text);

                count = 0;
                pos = 0;
                while (pos < text.size()) {
                    switch (text.at(pos)) {
                        case 'a':
                        case 'A':
                        case 'e':
                        case 'E':
                        case 'i':
                        case 'I':
                        case 'o':
                        case 'O':
                        case 'u':
                        case 'U':
                            ++count;
                            break;
                    }
                    ++pos;
                }
                
                cout << "There are " << count << " vowels in the text." << endl;

                break;
            case 'P':
            case 'p':
                count5 = 0;
                for (int i = 0; i < 1000; ++i) {
                    if (IsArmstrongNumber(i)) {
                        cout << i << " ";
                        ++count5;
                        if (count5 == 5) {
                            cout << endl;
                            count5 = 0;
                        }
                    }
                }
                cout << endl;

                break;
            case 'E':
            case 'e':
                break;
            default:
                cout << "Warning: invalid choice! Enter S,s or L,l or C,c or E,e only please." << endl; 
        }
    }
    while (!(user_choice == 'E' || user_choice == 'e'));
    
    cout << "The fun is over. Have a nice day!!!" << endl;
    exit(0);

    return 0;
}

bool IsArmstrongNumber(int n) {
    int digit = 0;
    int original_n = n;
    int sum_of_cubes = 0;

    while (n > 0) {
        digit = n % 10; 
        sum_of_cubes += pow(digit, 3);
        n /= 10;
    }

    return original_n == sum_of_cubes;
}