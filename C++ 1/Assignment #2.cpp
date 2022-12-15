//============================================================================
// File Name   : main.cpp
// Author      : Jinrui Du
// Copyright   : Copyright 2022 Jinrui Du
// Description : This program is a simple mortgage calculation program that helps 
//               perspective borrowers calculate monthly mortgage payments and property tax. 
// Disclaimer  : This is assignment 2.
// Revision History:
// Date              Version     Change ID         Author             Comment
// 18-10-22          1.0            001           Jinrui Du        Initial creation
//============================================================================

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

const double g_kAnnualTaxRate = 1.5;

void  Delay (int  milliseconds,  std::string delay_msg = "",  char  delay_symbol = '.') ;

int main ()  {
    int zip_code;
    string full_address;
    string loan_maturity_date;
    double offer_price = 0.0;
    double down_payment_pct = 0.0;
    int no_years_of_financing = 0;
    double annual_interest_rate_pct = 0.0;
    double total_down_payment = 0.0;
    double loan_amount = 0.0;
    double monthly_interest_rate = 0.0;
    double monthly_mortgage_payment = 0.0;
    double monthly_property_tax = 0.0;
    double total_monthly_payment_including_tax = 0.0;
    double total_payment_without_tax = 0.0;

    cout << "Enter property zip code: ";
    cin >> zip_code;
    cout << "Enter property address: ";
    cin.ignore();
    getline(cin, full_address);
    cout << "Enter property offer price: $";
    cin >>  offer_price;
    cout << "Enter down payment (in percentage %): ";
    cin >> down_payment_pct;
    cout << "Enter number of years financing: ";
    cin >> no_years_of_financing;
    cout << "Enter annual interest rate (in percentage %): ";
    cin >> annual_interest_rate_pct;

    Delay(8000, "Mortgage calculator is processing your data. Please wait ...",  '*');

    total_down_payment = offer_price * down_payment_pct / 100;
    loan_amount = offer_price - total_down_payment;
    loan_maturity_date = "12/31/" + to_string(2022 + no_years_of_financing);
    monthly_interest_rate = annual_interest_rate_pct / 1200;
    monthly_mortgage_payment = loan_amount * monthly_interest_rate / (1 - 1 / pow(1 + monthly_interest_rate, no_years_of_financing * 12));
    monthly_property_tax = offer_price * g_kAnnualTaxRate / 100 / 12;
    total_monthly_payment_including_tax = monthly_mortgage_payment + monthly_property_tax;
    total_payment_without_tax = monthly_mortgage_payment * 12 * no_years_of_financing;

    cout << fixed << setprecision(2);
    cout << endl << endl;
    cout << "\t\t*************************************" << endl;
    cout << "\t\t     MORTGAGE CALCULATOR RESULTS" << endl;
    cout << "\t\t*************************************" << endl;
    cout << "Property address: " << full_address << " " << zip_code << endl;
    cout << "Property offer price:                                      $" << setw(12) << offer_price << endl;
    cout << "Total down payment:                                        $" << setw(12) << total_down_payment << endl; 
    cout << "Loan amount:                                               $" << setw(12) << loan_amount << endl;
    cout << "Loan maturity date:                                         " << loan_maturity_date << endl;
    cout << "Monthly mortgate payment:                                  $" << setw(12) << monthly_mortgage_payment << endl;
    cout << "Total monthly payment (property tax included):             $" << setw(12) << total_monthly_payment_including_tax << endl;
    cout << "Total payment (exclude tax):                               $" << setw(12) << total_payment_without_tax << endl; 

    return 0;
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