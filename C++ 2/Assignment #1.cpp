//============================================================================
// File Name   : main.cpp
// Author      : Jinrui Du
// Copyright   : Copyright 2023 Jinrui Du
// Description : This is a simple movie ticket master system.
// Disclaimer  : This is assignment 1.
// Revision History:
// Date              Version     Change ID         Author             Comment
// 25-Jan-2023         1.0          001           Jinrui Du        Initial creation
//============================================================================

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Movie {
    private:
        string name;
        int seats_available;
        double ticket_price;
    public:
        static const string DEFAULT_MOVIE_NAME;
        static const int DEFAULT_SEATS;
        static const double DEFAULT_PRICE;
        Movie();
        Movie(string name, int seats_available, double ticket_price);
        ~Movie();
        string get_name() const;
        Movie * set_name(string name);
        int get_seats_available() const;
        Movie * set_seats_available(int seats_available);
        double get_ticket_price() const;
        Movie * set_ticket_price(double ticket_price);
        double PurchaseTicket(int n_seats_requested);
        void Display() const;
};

class MovieTicketMaster {
    public:
        static const int ARRAY_SIZE = 32;
        static const int DEFAULT_MOVIE_COUNT;
        static const string DEFAULT_NAME;
        static const string DEFAULT_LOCATION;
    private:
        string name;
        string location;
        int movie_count;
        Movie * const p_movie_list;
    public:
        MovieTicketMaster();
        MovieTicketMaster(string name, string location, int movie_count);
        ~MovieTicketMaster();
        string get_name() const;
        MovieTicketMaster * set_name(string name);
        string get_location() const;
        MovieTicketMaster * set_location(string location);
        int get_movie_count() const;
        MovieTicketMaster * set_movie_count(int movie_count);
        void Init();
        void Run() const;
    private:
        void Sort() const;
        void Menu() const;
        void ViewShowingMovies() const;
        Movie * SearchMovie() const;
        Movie * FindMovie(string query) const;
        void PurchaseTicket() const; 

};

int main() {
    MovieTicketMaster * p_movie_ticket_master = new MovieTicketMaster("nomen", "locus", MovieTicketMaster::DEFAULT_MOVIE_COUNT);

    p_movie_ticket_master->Init();
    p_movie_ticket_master->Run();

    delete p_movie_ticket_master;
    p_movie_ticket_master = nullptr;

    return 0;
}

const string Movie::DEFAULT_MOVIE_NAME = "Mystery Movie";
const int Movie::DEFAULT_SEATS = 100;
const double Movie::DEFAULT_PRICE = 14.99;

Movie::Movie() : name(Movie::DEFAULT_MOVIE_NAME),
                 seats_available(Movie::DEFAULT_SEATS),
                 ticket_price(Movie::DEFAULT_PRICE) {}
Movie::Movie(string name, int seats_available, double ticket_price) {
    this->name = name;
    this->seats_available = seats_available;
    this->ticket_price = ticket_price;
}
Movie::~Movie() {
    cout << "Movie " << name << " is no longer showing." << endl;
}

string Movie::get_name() const {return name;}
Movie * Movie::set_name(string name) {
    this->name = name;
    return this;
}
int Movie::get_seats_available() const {return seats_available;}
Movie * Movie::set_seats_available(int seats_available) {
    this->seats_available = seats_available;
    return this;
}
double Movie::get_ticket_price() const {return ticket_price;}
Movie * Movie::set_ticket_price(double ticket_price) {
    this->ticket_price = ticket_price;
    return this;
}


double Movie::PurchaseTicket(int n_seats_requested) {
    double total_cost = 0.0;

    if (n_seats_requested > seats_available) {
        return -1;
    }
    else {
        total_cost = n_seats_requested * ticket_price;
        seats_available -= n_seats_requested;
        return total_cost;
    } 
}

void Movie::Display() const {
    cout << left << setw(30) << name;
    cout << right << setw(5) << fixed << setprecision(2) << ticket_price << " $";
    cout << right << setw(30) << to_string(seats_available) + " seats available";
    cout << endl;
}

const int MovieTicketMaster::DEFAULT_MOVIE_COUNT = 0;
const string MovieTicketMaster::DEFAULT_NAME = "AMC";
const string MovieTicketMaster::DEFAULT_LOCATION = "My City";

MovieTicketMaster::MovieTicketMaster() : name(MovieTicketMaster::DEFAULT_NAME),
                                         location(MovieTicketMaster::DEFAULT_LOCATION),
                                         movie_count(MovieTicketMaster::DEFAULT_MOVIE_COUNT),
                                         p_movie_list(new Movie[MovieTicketMaster::ARRAY_SIZE]) {}
MovieTicketMaster::MovieTicketMaster(string name, 
                                     string location, 
                                     int movie_count) : name(name),
                                                        location(location),
                                                        movie_count(movie_count),
                                                        p_movie_list(new Movie[MovieTicketMaster::ARRAY_SIZE]) {}
MovieTicketMaster::~MovieTicketMaster() {
    delete[] p_movie_list;
    cout << "Theater " << name << " at " << location << " is currently closed." << endl;
}

string MovieTicketMaster::get_name() const {return name;}
MovieTicketMaster * MovieTicketMaster::set_name(string name) {
    this->name = name;
    return this;
}
string MovieTicketMaster::get_location() const {return location;}
MovieTicketMaster * MovieTicketMaster::set_location(string location) {
    this->location = location;
    return this;
}
int MovieTicketMaster::get_movie_count() const {return movie_count;}
MovieTicketMaster * MovieTicketMaster::set_movie_count(int movie_count) {
    this->movie_count = movie_count;
    return this;
}

void MovieTicketMaster::Init() {
    const int kSize = 8;
    Movie * p_movie = nullptr;
    string * p_name = nullptr;
    int * p_seats_available = nullptr;
    double * p_price = nullptr;

    string movie_name_list[kSize] = {"Avatar 2", 
                                     "The Wandering Earth 2", 
                                     "Kick Ass", 
                                     "Kill Tom", 
                                     "The Beautiful Brain",
                                     "Code",
                                     "NSA",
                                     "Community"};
    int seat_available_list[kSize] = {3, 
                                      20, 
                                      30, 
                                      2, 
                                      0,
                                      10,
                                      5,
                                      0};
    double price_list[kSize] = {24.99, 
                                14.99,
                                9.99,
                                14.99,
                                9.99,
                                14.99,
                                29.99,
                                9.99};

    p_movie = p_movie_list;
    p_name = movie_name_list;
    p_seats_available = seat_available_list;
    p_price = price_list;

    for (int i = 0; i < kSize; ++i) {
        p_movie->set_name(*p_name)
               ->set_seats_available(*p_seats_available)
               ->set_ticket_price(*p_price);
        ++p_movie;
        ++p_name;
        ++p_seats_available;
        ++p_price;
    }

    movie_count = kSize;
    Sort();
}

void MovieTicketMaster::Run() const {
    int user_choice = 0;
    bool quit = false;
    int c = 0;
    do {
        Menu();
        cin >> user_choice;
        switch (user_choice) {
            case 1:
                ViewShowingMovies();
                break;
            case 2:
                SearchMovie();
                break;
            case 3:
                PurchaseTicket();
                break;
            case 4:
                quit = true;
                break;
            default:
                break;
        } 
    }
    while (!quit);
}


void MovieTicketMaster::Menu() const {
    cout << setw(30) << "MOVIE TICKET MASTER" << endl;
    cout << setw(30) << "Theater:  " + name + " at " + location << endl;
    cout << endl;
    cout << setw(30) << "FREE popcore and cocke!" << endl;
    cout << endl; 
    cout << setw(30) << "1. View all showing movies" << endl; 
    cout << setw(30) << "2. Search a movie" << endl;
    cout << setw(30) << "3. Purchase a ticket" << endl;
    cout << setw(30) << "4. Quit" << endl;
}

void MovieTicketMaster::ViewShowingMovies() const {
    Movie * p_movie = nullptr;
    p_movie = p_movie_list;
    for (int i = 0; i < movie_count; ++i) {
        p_movie->Display();
        ++p_movie;
    }
}

void MovieTicketMaster::Sort() const {
    Movie temp;
    bool swapped = true;
    int j = 0;
    Movie * p_movie = nullptr;

    while (swapped) {
        swapped = false;
        ++j;
        p_movie = p_movie_list;
        for (int i = 0; i < movie_count - j; ++i) {
            if ((p_movie + 1)->get_name().compare(p_movie->get_name()) < 0) {
                temp = *p_movie;
                *p_movie = *(p_movie + 1);
                *(p_movie + 1) = temp;
                swapped = true;
            }
            ++p_movie;
        }
    }
}

Movie * MovieTicketMaster::SearchMovie() const {
    Movie * p_movie = nullptr;
    string query;
    cout << "Please enter the name of the movie: ";
    if (cin.peek() == '\n') {
        cin.ignore();
    }
    getline(cin, query);
    p_movie = FindMovie(query);
    if (p_movie != nullptr) {
        p_movie->Display();
    } 
    else {
        cout << "ERROR! No movie with the name \"" << query << "\" are found!" << endl;
    }
    return p_movie;
}

Movie * MovieTicketMaster::FindMovie(string query) const {
    Movie * p_movie = p_movie_list;
    int start_pos = 0;
    int end_pos = movie_count - 1;
    int middle_pos = 0;
    int compare = 0;

    while (start_pos <= end_pos) {
        middle_pos = (start_pos + end_pos) / 2;
        compare = (p_movie_list + middle_pos)->get_name().compare(query);
        if (compare == 0) {
            return p_movie + middle_pos;
        }
        else if (compare < 0) {
            start_pos = middle_pos + 1;
        }
        else {
            end_pos = middle_pos - 1;
        }
    }

    return nullptr;
}

void MovieTicketMaster::PurchaseTicket() const {
    int n_tickets = 0;
    double cost = 0.0;
    Movie * p_movie = nullptr;
    p_movie = SearchMovie();
    if (p_movie != nullptr) {
        cout << "Please enter the number of tickets: ";
        cin >> n_tickets;
        cost = p_movie->PurchaseTicket(n_tickets);
        if (cost != -1) {
            cout << "The total cost is: " << cost << endl;
        }
        else {
            cout << "The show has been sold out or not enough tickets available per your request!" << endl;
        }
    }
}