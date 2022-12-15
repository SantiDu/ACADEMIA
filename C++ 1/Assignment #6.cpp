//============================================================================
// File Name   : main.cpp
// Author      : Jinrui Du
// Copyright   : Copyright 2022 Jinrui Du
// Description : This is a fruit ordering system.
// Disclaimer  : This is assignment 6.
// Revision History:
// Date              Version     Change ID         Author             Comment
// 03-Dec-22           1.0          001           Jinrui Du        Initial creation
//============================================================================

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Fruit {
    private:
        string name;
        double weight;
        double price_per_lbs;
    public:
        static const string DEFAULT_NAME;
        static const double DEFAULT_WEIGHT;
        static const double DEFAULT_PRICE_PER_LBS;
    public:
        Fruit();
        Fruit(string name, double weight, double price_per_lbs);
        ~Fruit();
    public:
        string get_name() const;
        double get_weight() const;
        double get_price_per_lbs() const;
        Fruit& set_name(string name);
        Fruit& set_weight(double weight);
        Fruit& set_price_per_lbs(double price_per_lbs);
        double Order(double ordered_weight);
        void Display() const;
};

class OnlineSuperMarket {
    public:
        static const int ARRAY_SIZE = 8;
    private:
        Fruit fruits[OnlineSuperMarket::ARRAY_SIZE];
        string name;
        string website;
    public:
        static const double TAX_RATE;
        static const string DEFAULT_NAME;
        static const string DEFAULT_WEBSITE;
    public:
        OnlineSuperMarket();
        OnlineSuperMarket(string name, string website);
        ~OnlineSuperMarket();
    private:
        int Find(string fruit_name) const;
        void Quit() const;
    public:
        string get_name() const;
        string get_website() const;
        void Init();
        void Sort();
        void Run();
        void ShowFruits() const;
};

int main() {
    OnlineSuperMarket* p_online_supermarket = nullptr;
    p_online_supermarket = new OnlineSuperMarket("Fruitly Garden", "https://www.fruitlygarden.com");
    p_online_supermarket->ShowFruits();
    p_online_supermarket->Init();
    p_online_supermarket->ShowFruits();
    p_online_supermarket->Sort();
    p_online_supermarket->ShowFruits();
    p_online_supermarket->Run();
}

const string Fruit::DEFAULT_NAME = "?";
const double Fruit::DEFAULT_WEIGHT = 0.0;
const double Fruit::DEFAULT_PRICE_PER_LBS = 0.0;

Fruit::Fruit() : name(Fruit::DEFAULT_NAME),
                 weight(Fruit::DEFAULT_WEIGHT),
                 price_per_lbs(Fruit::DEFAULT_PRICE_PER_LBS) {}
Fruit::Fruit(string name, double weight, double price_per_lbs) {
    this->name = name;
    this->weight = weight;
    this->price_per_lbs = price_per_lbs;
}
Fruit::~Fruit() {
    cout << "Fruit " << name << ", Weight = " << weight << "lbs rotten." << endl;
}

string Fruit::get_name() const {return name;}
double Fruit::get_weight() const {return weight;}
double Fruit::get_price_per_lbs() const {return price_per_lbs;}
Fruit& Fruit::set_name(string name) {
    this->name = name;
    return *this;
}
Fruit& Fruit::set_weight(double weight) {
    this->weight = weight;
    return *this;
}
Fruit& Fruit::set_price_per_lbs(double price_per_lbs) {
    this->price_per_lbs = price_per_lbs;
    return *this;
}

double Fruit::Order(double ordered_weight) {
    if (ordered_weight > weight) {
        return -1;
    }
    else {
        weight -= ordered_weight;
        return ordered_weight * price_per_lbs;
    }
}

void Fruit::Display() const {
    cout << fixed << setprecision(2);
    cout << "Fruit name:    " << setw(10) << name << endl;
    cout << "Fruit weight:  " << setw(10) << weight << endl;
    cout << "Price per lbs: " << setw(10) << price_per_lbs << endl;
}


const double OnlineSuperMarket::TAX_RATE = 0.09375;
const string OnlineSuperMarket::DEFAULT_NAME = "TBD";
const string OnlineSuperMarket::DEFAULT_WEBSITE = "https://www.unknown_store.com";

OnlineSuperMarket::OnlineSuperMarket() : name(OnlineSuperMarket::DEFAULT_NAME),
                                         website(OnlineSuperMarket::DEFAULT_WEBSITE) {}
OnlineSuperMarket::OnlineSuperMarket(string name, string website) {
    this->name = name;
    this->website = website;
}
OnlineSuperMarket::~OnlineSuperMarket() {
    cout << "Online super market " << name << " at " << website << " is closed." << endl;
}

int OnlineSuperMarket::Find(string fruit_name) const {
    int start_pos = 0;
    int end_pos = OnlineSuperMarket::ARRAY_SIZE - 1;
    int middle_pos = 0;
    int compare = 0;

    while (start_pos <= end_pos) {
        middle_pos = (start_pos + end_pos) / 2;
        compare = fruits[middle_pos].get_name().compare(fruit_name);
        if (compare == 0) {
            return middle_pos;
        }
        else if (compare < 0) {
            start_pos = middle_pos + 1;
        }
        else {
            end_pos = middle_pos - 1;
        }
    }

    return -1;
}

void OnlineSuperMarket::Quit() const {
    ShowFruits();
    cout << "Thanks for your visit. Please come again." << endl;
}

string OnlineSuperMarket::get_name() const {return name;}
string OnlineSuperMarket::get_website() const {return website;}

void OnlineSuperMarket::Init() {
    string names[OnlineSuperMarket::ARRAY_SIZE] = {"Apple", "Orange", "Banana", "Watermelon", "Cantaloupe", "Mango", "Dragon Fruit", "Durian"};
    double weights[OnlineSuperMarket::ARRAY_SIZE] = {20.0, 40.1, 30.2, 60.0, 50.1, 30.0, 24.2, 30.3};
    double prices[OnlineSuperMarket::ARRAY_SIZE] = {0.8, 1.0, 0.5, 3.0, 5.0, 2.0, 0.8, 10.0};
    
    for (int i = 0; i < OnlineSuperMarket::ARRAY_SIZE; ++i) {
        fruits[i].set_name(names[i])
                 .set_weight(weights[i])
                 .set_price_per_lbs(prices[i]);
    }
}

void OnlineSuperMarket::Sort() {
    bool swapped = true;
    Fruit temp;
    int j = 0;

    while (swapped) {
        swapped = false;
        ++j;
        for (int i = 0; i < OnlineSuperMarket::ARRAY_SIZE - j; ++i) {
            if (fruits[i].get_name().compare(fruits[i + 1].get_name()) > 0) {
                temp = fruits[i + 1];
                fruits[i + 1] = fruits[i];
                fruits[i] = temp;
                swapped = true;
            }
        }
    }
}

void OnlineSuperMarket::Run() {
    string order_name;
    double order_weight = 0.0;
    double total_price = 0.0;
    double total_cost = 0.0;
    int index = 0;

    cout << "\t\t" << name << endl;
    cout << "\t\t" << website << endl;

    do {
        cout << "Please order fruits (enter Q/q to quit): ";
        if (cin.peek() == '\n') {
            cin.ignore();
        }
        getline(cin, order_name);
        if (order_name == "Q" || order_name == "q") {
            Quit();
            break;
        }
        else {
            index = Find(order_name);
            switch (index) {
                case -1:
                    cout << "Error: fruit " << order_name << " not found!!" << endl;
                    cout << endl;
                    continue;
                default:
                    cout << "Please enter total weights (in lbs): ";
                    cin >> order_weight;
                    total_price = fruits[index].Order(order_weight);
                    if (total_price == -1) {
                        cout << "Error: order exceeds storage!!!" << endl;
                        cout << endl;
                    }
                    else {
                        if (order_weight > 0) {
                            total_cost = total_price + OnlineSuperMarket::TAX_RATE;
                        }
                        cout << "You ordered: " << endl;
                        cout << "Fruit: " << order_name << endl;
                        cout << "Weight: " << order_weight << endl;
                        cout << "Price: " << fruits[index].get_price_per_lbs() << endl;
                        cout << "Total cost (plus tax): " << total_cost << endl;
                        cout << endl;
                        total_cost = 0.0;
                    }
            }
        }
    }
    while (true);
}

void OnlineSuperMarket::ShowFruits() const {
    for (int i = 0; i < OnlineSuperMarket::ARRAY_SIZE; ++i) {
        fruits[i].Display();
        cout << endl;
    }
}