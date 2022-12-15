//============================================================================
// File Name   : main.cpp
// Author      : Jinrui Du
// Copyright   : Copyright 2022 Jinrui Du
// Description : This program allows sales agents to query the vehicle inventory per request.
// Disclaimer  : This is assignment 4.
// Revision History:
// Date              Version     Change ID         Author             Comment
// 12-11-22          1.0            001           Jinrui Du        Initial creation
//============================================================================

#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

void LoadVehicleInventory(string * make_model_list, int * year_list, double * price_list, const int kVehicleCount);
void Menu();
int GetUserChoice();
void Run(string * make_model_list, int * year_list, double * price_list, const int kVehicleCount);
void ShowVehicleInvenytory(string * make_model_list, int * year_list, double * price_list, const int kVehicleCount);
void SearchByMakeModel(string * make_model_list, int * year_list, double * price_list, const int kVehicleCount);
bool Quit();
void Delay (int milliseconds, std::string delay_msg = "", char delay_symbol = '.') ;

int main() {
    const int kVehicleCount = 16;
    string make_model_list[kVehicleCount];
    int year_list[kVehicleCount] = {0};
    double price_list[kVehicleCount] = {0.0}; 

    LoadVehicleInventory(make_model_list, year_list, price_list, kVehicleCount);
    Run(make_model_list, year_list, price_list, kVehicleCount);

    return 0;
}

void LoadVehicleInventory(string * make_model_list, int * year_list, double * price_list, const int kVehicleCount) {
    string make_model;
    int year = 0;
    double price = 0.0;
    int rand_make_model = 0;
    int rand_year = 0;
    const double kMinPriceFord = 9000.0;
    const double kMaxPriceFord = 30000.0;
    const double kMinPriceToyota = 12000.0;
    const double kMaxPriceToyota = 35000.0;
    const double kMinPriceBMW = 39500.0;
    const double kMaxPriceBMW = 63500.0;
    const double kMinPriceRR = 80000.0;
    const double kMaxPriceRR = 199999.0;
    srand (static_cast <unsigned int> (time (0))) ; // generate a seed for the random generator
    cout << "          Welcome to Foothill Dearlership\n";
    Delay(1000, "Loading vehicles from database. Please wait ...",  '*');
    for (int i = 0; i < kVehicleCount; i++) {
        rand_make_model = rand() % 4;   // generate either 0, 1, 2 or 3
        switch (rand_make_model) {
            case 0:
                make_model = "Ford Taurus";
                price = kMinPriceFord + static_cast<double> (rand()) / (static_cast<double> (RAND_MAX / (kMaxPriceFord - kMinPriceFord)));
                break;
            case 1:
                make_model = "Toyota Camry";
                price = kMinPriceToyota + static_cast<double> (rand()) / (static_cast<double> (RAND_MAX / (kMaxPriceToyota - kMinPriceToyota)));
                break;
            case 2:
                make_model = "BMW 335i";
                price = kMinPriceBMW + static_cast<double> (rand()) / (static_cast<double> (RAND_MAX / (kMaxPriceBMW - kMinPriceBMW)));
                break;
            case 3:
                make_model = "Rolls-Royce Phantom";
                price = kMinPriceRR + static_cast<double> (rand()) / (static_cast<double> (RAND_MAX / (kMaxPriceRR - kMinPriceRR)));
                break;
            default:
                ;
        }
        rand_year = rand() % 8;  // generate a random integer in [0, 7]
        year = 2010 + rand_year;

        make_model_list[i] = make_model;
        year_list[i] = year;
        price_list[i] = price;
    }      
    cout << endl;
}

void Menu() {
    cout << "    SMART CAR INQUIRY" << endl;
    cout << " 1. View Vehicle Inventory" << endl;
    cout << " 2. Search by make and model" << endl;
    cout << " 3. Quit" << endl;
}

int GetUserChoice() {
    int choice = 0;

    cout << "    Enter your choice: ";
    cin >> choice;

    return choice;
}

void Run(string * make_model_list, int * year_list, double * price_list, const int kVehicleCount) {
    int user_choice = 0;
    int not_quit = true;

    do {
        Menu();
        user_choice = GetUserChoice();
        switch (user_choice) {
            case 1:
                ShowVehicleInvenytory(make_model_list, year_list, price_list, kVehicleCount);
                break;
            case 2:
                SearchByMakeModel(make_model_list, year_list, price_list, kVehicleCount);
                break;
            case 3:
                not_quit = Quit();
                break;
            default:
                cout << "Warning: please provide a valid input!";
        }
    }
    while (not_quit);
}

void ShowVehicleInvenytory(string * make_model_list, int * year_list, double * price_list, const int kVehicleCount) {
    cout << "--------------------------------------------" << endl;
    cout << "|             VEHICLE INVENTORY            |" << endl;
    cout << "--------------------------------------------" << endl;
    cout << fixed << setprecision(2);
    for (int i = 0; i < kVehicleCount; ++i) {
        cout << setw(19) << right << make_model_list[i] << "\t" << year_list[i] << "\t$" << setw(9) << price_list[i] << endl;
    }
    cout << endl;
}

void SearchByMakeModel(string * make_model_list, int * year_list, double * price_list, const int kVehicleCount) {
    string make_model;

    if (cin.peek() == '\n') {
        cin.ignore();
    }
    cout << "Enter make and model: ";
    getline(cin, make_model);

    for (int i = 0; i < kVehicleCount; ++i) {
        if (make_model == make_model_list[i]) {
            cout << make_model << "\t" << year_list[i] << "\t$" << price_list[i] << endl;
        }
    }
    cout << endl;
}

bool Quit() {
    cout << "The fun is over. Have a nice day!!!" << endl;

    return false;
}

void Delay(int milliseconds, std::string delay_message, char delay_symbol) {
    const int kCyclesPerMilliSecond = 600000;
    std::cout << delay_message << std::flush ;
    for (int millisecond = 0; millisecond < milliseconds; ++millisecond) {
        for(int cycle = 0; cycle <= kCyclesPerMilliSecond; ++cycle) {
            if (millisecond % 1000 == 0 && cycle == kCyclesPerMilliSecond) {  // print a symbol every second
                std::cout << delay_symbol << std::flush;
            }
        }                         
    }
}