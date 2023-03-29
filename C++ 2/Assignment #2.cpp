//============================================================================
// File Name   : main.cpp
// Author      : Jinrui Du
// Copyright   : Copyright 2023 Jinrui Du
// Description : This is an inventory management system for an electronics store.
// Disclaimer  : This is assignment 2.
// Revision History:
// Date              Version     Change ID         Author             Comment
// 06-Feb-2023         1.0          001           Jinrui Du        Initial creation
//============================================================================

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>

using namespace std;


void SpecialEffect(int milliseconds, string message, char symbol);

template <typename T>
T & ConvertToType(istringstream & isstream, string & buffer, T & obj);


class InventoryItem {
    protected:
        int item_id;
        bool restocking;
    public:
        static const int DEFAULT_ITEM_ID;
        static const bool DEFAULT_RESTOCKING;
    
        InventoryItem();
        InventoryItem(int item_id, bool restocking);
        ~InventoryItem();

        int get_item_id() const;
        InventoryItem * set_item_id(int item_id);
        bool is_restocking() const;
        InventoryItem * set_restocking(bool restocking);

        void Display() const;
};

class Product : public InventoryItem {
    private:
        string name;
        int quantity;
        double price;
    public:
        static const string DEFAULT_NAME;
        static const int DEFAULT_QUANTITY;
        static const double DEFAULT_PRICE;
    
        Product();
        Product(int item_id, bool restocking, string name, int quantity, double price);
        ~Product();

        string get_name() const;
        Product * set_name(string name);
        int get_quantity() const;
        Product * set_quantity(int quantity);
        double get_price() const;
        Product * set_price(double price);

        void Display() const;
        double Cost(int quantity) const;
};

class InventorySystem {
    public:
        static const int ARRAY_SIZE = 512;
    private:
        string store_name;
        int product_count;
        InventoryItem * product_list[InventorySystem::ARRAY_SIZE];
    public:
        static const string DEFAULT_STORE_NAME;
        static const int DEFAULT_PRODUCT_COUNT;
        static const string INPUT_FILE_NAME;
        static const string OUTPUT_FILE_NAME; 

        InventorySystem();
        InventorySystem(string store_name);
        ~InventorySystem();

        string get_store_name() const;
        InventorySystem * set_store_name(string store_name);
        int get_product_count() const;
        InventorySystem * set_product_count(int product_count);

        void BuildInventory();
        void ShowInventory() const;
        void UpdateInventory();
        void Discontinue();
        void Terminate() const;
    private:
        InventoryItem * FindInventoryItem(int item_id) const;
};


int main() {
    bool quit = false;
    int item_id = 0;
    int no_of_times_to_run = 0;
    InventorySystem * p_system = nullptr;
    p_system = new InventorySystem("Mr. Robot's Wires");

    p_system->BuildInventory();
    p_system->ShowInventory();
    no_of_times_to_run = 4;
    for (int i = 0; i < no_of_times_to_run; ++i) {
        cout << "Task: UpdateInventory" << endl;
        p_system->UpdateInventory();
        p_system->ShowInventory();
    }
    while (!quit) {
        cout << "Task: Discontinue" << endl;
        p_system->Discontinue();
        p_system->ShowInventory();
        cout << "Quit? (input 1 for yes 0 for no): ";
        cin >> quit; 
    } 
    p_system->Terminate();

    delete p_system;

    return 0;
}


void SpecialEffect(int milliseconds, string message, char symbol) {
    const int kCyclesPerMilliSecond = 600000;
    cout << message;
    for (int millisecond = 0; millisecond < milliseconds; ++millisecond) {
        for(int cycle = 0; cycle <= kCyclesPerMilliSecond; ++cycle) {
            if (millisecond % 100 == 0 && cycle == kCyclesPerMilliSecond) {
                cout << symbol << flush;
            }
        }                         
    }
}

template <typename T>
T & ConvertToType(istringstream & isstream, string & buffer, T & obj) {
    isstream.clear();
    isstream.str(buffer);
    isstream >> obj;
    return obj;
}


const int InventoryItem::DEFAULT_ITEM_ID = 9999;
const bool InventoryItem::DEFAULT_RESTOCKING = false;

InventoryItem::InventoryItem() : item_id(InventoryItem::DEFAULT_ITEM_ID), 
                                 restocking(InventoryItem::DEFAULT_RESTOCKING) {}
InventoryItem::InventoryItem(int item_id, 
                             bool restocking) : item_id(item_id),
                                                restocking(restocking) {}
InventoryItem::~InventoryItem() {
    cout << "InventoryItem " << item_id << " with " << restocking << " restocking destroyed..." << endl;
}

int InventoryItem::get_item_id() const {return item_id;}
InventoryItem * InventoryItem::set_item_id(int item_id) {
    this->item_id = item_id;
    return this;
}
bool InventoryItem::is_restocking() const {return restocking;}
InventoryItem * InventoryItem::set_restocking(bool restocking) {
    this->restocking = restocking;
    return this;
}

void InventoryItem::Display() const {
    cout << "Item id: " << setw(4) << setfill('0') << item_id << setfill(' ') << " | ";
    cout << "Is Restocking: " << setw(4) << (restocking ? "Yes" : "No") << " | ";
}


const string Product::DEFAULT_NAME = "No Product";
const int Product::DEFAULT_QUANTITY = 0;
const double Product::DEFAULT_PRICE = 0.99;

Product::Product() : InventoryItem(),
                     name(Product::DEFAULT_NAME),
                     quantity(Product::DEFAULT_QUANTITY),
                     price(Product::DEFAULT_PRICE) {}
Product::Product(int item_id, 
                 bool restocking, 
                 string name, 
                 int quantity, 
                 double price) : InventoryItem(item_id, restocking),
                                 name(name),
                                 quantity(quantity),
                                 price(price) {}
Product::~Product() {
    Display();
    cout << "destroyed..." << endl;
}

string Product::get_name() const {return name;}
Product * Product::set_name(string name) {
    this->name = name;
    return this;
}
int Product::get_quantity() const {return quantity;}
Product * Product::set_quantity(int quantity) {
    this->quantity = quantity;
    return this;
}
double Product::get_price() const {return price;}
Product * Product::set_price(double price) {
    this->price = price;
    return this;
}

void Product::Display() const {
    InventoryItem::Display();
    cout << "Name: " << setw(20) << name << " | ";
    cout << "Quantity: " << setw(5) << quantity << " | ";
    cout << "Price: " << fixed << setprecision(2) << setw(10) << price << " | ";
    if (restocking) {
        SpecialEffect(1000, "Restocking", '*');
    }
    cout << endl;
}

double Product::Cost(int quantity) const {
    double total_cost = 0.0;
    total_cost = quantity * price;
    return total_cost;
}


const string InventorySystem::DEFAULT_STORE_NAME = "My Store";
const int InventorySystem::DEFAULT_PRODUCT_COUNT = 0;
const string InventorySystem::INPUT_FILE_NAME = "InputProducts.txt";
const string InventorySystem::OUTPUT_FILE_NAME = "OutputProducts.txt";

InventorySystem::InventorySystem() : store_name(InventorySystem::DEFAULT_STORE_NAME), 
                                     product_count(InventorySystem::DEFAULT_PRODUCT_COUNT) {
                                        for (auto & p_product : product_list) {
                                            p_product = nullptr;
                                        }
                                     } 
InventorySystem::InventorySystem(string store_name) : store_name(store_name),
                                                      product_count(InventorySystem::DEFAULT_PRODUCT_COUNT) {
                                                        for (auto & p_product : product_list) {
                                                            p_product = nullptr;
                                                        }
                                                      }
InventorySystem::~InventorySystem() {
    InventoryItem ** p_p_item = product_list;
    for (int i = 0; i < product_count; ++i) {
        delete static_cast<Product *>(*p_p_item++);
    }
}

string InventorySystem::get_store_name() const {return store_name;}
InventorySystem * InventorySystem::set_store_name(string store_name){
    this->store_name = store_name;
    return this;
}
int InventorySystem::get_product_count() const {return product_count;}
InventorySystem * InventorySystem::set_product_count(int product_count) {
    this->product_count = product_count;
    return this;
}

InventoryItem * InventorySystem::FindInventoryItem(int item_id) const {
    InventoryItem * const * p_p_item = product_list;
    // int count = 0;
    // for (auto *p_p_item : product_list) {
    //     //TODO:
    //     if (++count == product_count) {
    //         break;
    //     }
    // }
    for (int i = 0; i < product_count; ++i) {
        if ((*p_p_item)->get_item_id() == item_id) {
            return *p_p_item;
        }
        ++p_p_item;
    }
    return nullptr;
}

void InventorySystem::BuildInventory() {
    int count = 0;
    int item_id = 0;
    int quantity = 0;
    double price = 0.0;
    string product_name;
    string buffer;
    istringstream isstream;
    ifstream fin(InventorySystem::INPUT_FILE_NAME);

    if (!fin) {
        cout << "ERROR: Failed to open input file" << endl;
        exit(5);
    }    

    while (getline(fin, buffer, ';')) {
        item_id = ConvertToType<int>(isstream, buffer, item_id);
        getline(fin, buffer, ';');
        product_name = buffer;
        getline(fin, buffer, ';');
        quantity = ConvertToType<int>(isstream, buffer, quantity);
        getline(fin, buffer, '\n');
        price = ConvertToType<double>(isstream, buffer, price);
        product_list[count++] = new Product(item_id, quantity == 0, product_name, quantity, price);
    }
    product_count = count;

    fin.close();
}

void InventorySystem::ShowInventory() const {
    InventoryItem * const * p_p_item = product_list;
    for (int i = 0; i < product_count; ++i) {
        static_cast<Product *>(*p_p_item++)->Display();
    }
}

void InventorySystem::UpdateInventory() {
    int item_id = 0;
    int quantity = 0;
    int quantity_updated = 0;
    InventoryItem * p_item = nullptr;
    Product * p_product = nullptr;

    cout << "Please input item id: ";
    cin >> item_id;
    cout << "Please input quantity: ";
    cin >> quantity;

    p_item = FindInventoryItem(item_id);
    p_product = static_cast<Product *>(p_item);

    if (p_product != nullptr) {
        quantity_updated = p_product->get_quantity() - quantity;
        if (quantity_updated >= 0) {
            cout << "The total cost is: " << p_product->Cost(quantity) << endl;
            p_product->set_quantity(quantity_updated);
            if (quantity_updated == 0) {
                p_product->set_restocking(true);
                cout << "Please restock " << p_product->get_name() << endl;
            }
        }
        else {
            cout << "ERROR: There are only " << p_product->get_quantity() << ' ';
            cout << p_product->get_name() << " left" << endl;
        }
    }
    else {
        cout << "ERROR: Cannot Update. Item with ID " << item_id << " is NOT found!" << endl;
    }
}

void InventorySystem::Discontinue() {
    InventoryItem ** p_p_item = nullptr;
    int i = 0;
    int item_id = 0;
    bool item_found = false;

    cout << "Enter the id of the product to be discontinued: ";
    cin >> item_id;

    p_p_item = product_list;
    for (; i < product_count; ++i) {
        if ((*p_p_item)->get_item_id() == item_id) {
            item_found = true;
            delete static_cast<Product *>(*p_p_item);
            *p_p_item = nullptr;
            break;
        }
        ++p_p_item;
    }

    if (item_found) {
        for (; i < product_count - 1; ++i) {
            *p_p_item = *(p_p_item + 1);
            ++p_p_item;
        }
        *p_p_item = nullptr;
        --product_count;
    }
    else {
        cout << "ERROR: Cannot discontinue. Item with ID " << item_id << " is NOT found!" << endl;
    }
}

void InventorySystem::Terminate() const {
    int item_id = 0;
    int quantity = 0;
    double price = 0.0;
    string product_name;
    InventoryItem * const * p_p_item = nullptr;
    Product * p_product = nullptr;
    ofstream fout(InventorySystem::OUTPUT_FILE_NAME);

    if (!fout) {
        cout << "ERROR: Failed to open output file." << endl;
        exit(5);
    }

    p_p_item = product_list;
    for (int i = 0; i < product_count; ++i) {
        p_product = static_cast<Product *>(*p_p_item);

        item_id = p_product->get_item_id();
        quantity = p_product->get_quantity();
        price = p_product->get_price();
        product_name = p_product->get_name();
        
        fout << item_id << ';';
        fout << product_name << ';';
        fout << quantity << ';';
        fout << price << endl;

        ++p_p_item;
    } 

    fout.close();
}