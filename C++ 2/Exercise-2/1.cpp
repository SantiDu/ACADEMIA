//=====================================================================================
// Name        : Pointers.cpp
// Author      : CS 2B
// Date        : Winter 2021
// Version     :
// Copyright   : Copyright (C). CS Department Foothill College 2015. All rights reserved.
// Program purpose: Illustration of variables and their memory addresses        

// Revisions history: (date/programmer/what changed)
//=====================================================================================                           

#include <iostream>
#include <iomanip>

using namespace std;

class MovieTicket {
   private:
        string seat;
        double price;
   public:
           // construstors/destructor/member functions ...
};

int main() {
    int count = 10;
    double price = 5.99;
    MovieTicket  ticket;

    cout << "count's value: " << count << endl;
    cout << "count's memory address: " << hex << "0x" << &count << endl;

    cout << "price's value: " << fixed << setprecision(2) << price << endl;
    cout << "price's memory address: " << hex << "0x" << &price << endl;

    cout << "MovieTicket object's memory address: " << hex << "0x" << &ticket << endl;

    cout << "--------------------------------------------\n\n" ;

    const int  kSize = 4;
    int list[kSize] = {10, 20, 30, 40 };

    cout << "Print array elements' values and memory addresses:"  << endl;
    cout << "--------------------------------------------\n";
    cout << "Element\t\tValue\t\tAddress\n";
    cout << "--------------------------------------------\n";


    for ( int i = 0; i < kSize; ++i ) {
        cout << setw(3) << "[" << i << "]\t\t" << dec << list[i] << "\t\t" << hex << "0x" << &list[i] << endl;
    }

    return 0;
}