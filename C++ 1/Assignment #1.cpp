//============================================================================
// File Name   : main.cpp
// Author      : Jinrui Du
// Copyright   : Copyright 2022 Jinrui Du
// Description : This program prints out a movie ticket stub for Adult Admission at AMC Universal CityWalk.
// Disclaimer  : This is assignment 1.
// Revision History:
// Date              Version     Change ID         Author             Comment
// 01-10-22          1.0            001           Jinrui Du        Initial creation
//============================================================================

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main ()  {
    int day = 0;
    int month = 0;
    int year = 0;
    int hour = 0;
    int minute = 0;
    int theatre_location = 0;
    double admission_price = 0.0;
    string movie_title;
    string movie_rating;
    string time_of_day;

    movie_title = "A Star is Born Encore";
    movie_rating = "PG-13";
    day = 10;
    month = 3;
    year = 2022;
    hour = 3;
    minute = 20;
    time_of_day = "PM";
    theatre_location = 10;
    admission_price = 12.75;

    cout << "----------------------------------------------------------------------------------------\n";
    cout << "                               AMC Universal CityWalk                          \n";
    cout << "                                    Presenting                                 \n";
    cout << "                               " << movie_title << "                            \n";
    cout << "         " << "Show time: " << hour << ":" << minute << " " << time_of_day;
    cout << "                            "; 
    cout << "Date: " << day << "/" << month << "/" << year << "\n";
    cout << "         " << "Theatre: " << theatre_location;
    cout << "                                   ";
    cout << movie_rating << "\n";
    cout << "         " << "Adult Admission: $" << admission_price << "\n";
    cout << "         " << "Don't forget to get your free small popcorn with 4 tickets or more!!!\n";
    cout << "----------------------------------------------------------------------------------------\n";
      
    return 0;
}