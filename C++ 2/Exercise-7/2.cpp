#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Vehicle {
    private:
        Vehicle * next;     // link to next Vehicle node
    protected:
        string make;
        int year;
    public:
        static const int DEFAULT_YEAR;
        static const string DEFAULT_MAKE;
    public:
        Vehicle();
        Vehicle(string make, int year);
        ~Vehicle();

        void set_next(Vehicle * p_vehicle);
        Vehicle * get_next() const;
        string get_make() const;
        int get_year() const;
        void Display() const;
};

class Boat : public Vehicle {
    public:
        Boat();
        Boat(string make, int year);
        ~Boat();

        void Display() const;
};

class Car : public Vehicle {
    private:
        int wheels;
    public:
        static const int DEFAULT_WHEELS;
    public:
        Car();
        Car(string make, int year, int wheels);
        ~Car();

        int get_wheels() const;
        void Display () const;     
};

class VehicleList {
    private:
        Vehicle * head;
    public:
        VehicleList();
        ~VehicleList();

        void InsertFront(Vehicle * p_vehicle);
        void InsertEnd(Vehicle * p_vehicle);
        void InsertSorted(Vehicle * p_vehicle);
        void RemoveFirst();
        Vehicle * Search(string make, int year) const;
        void ShowList() const;
        int CountNodes() const;
        bool Empty() const;
};

int main() { 
}

const int Vehicle::DEFAULT_YEAR = 1970;
const string Vehicle::DEFAULT_MAKE = "XYZ";

Vehicle::Vehicle() : next(nullptr), make(Vehicle::DEFAULT_MAKE), year(Vehicle::DEFAULT_YEAR) {}
Vehicle::Vehicle(string make, int year) : next(nullptr), make (make), year(year) {}
Vehicle::~Vehicle() {}

Vehicle * Vehicle::get_next() const {return next;}
void Vehicle::set_next(Vehicle * p_vehicle) {next = p_vehicle;}   // now next points to the p_vehicle passed in as parameter.         

string Vehicle::get_make() const {return make;}
int Vehicle::get_year() const {return year;}

void Vehicle::Display() const {
       cout << make << ", " << year << endl;
}


const int Car::DEFAULT_WHEELS = 4;

Car::Car() : Vehicle(), wheels(Car::DEFAULT_WHEELS) {}   
Car::Car(string make, int year, int wheels) : Vehicle(make, year), wheels(wheels) {}  
Car::~Car() {}

void Car::Display()  const {
        cout << "Car: " << endl;
        Vehicle::Display ( );
         cout << "Number of wheels: " << wheels << endl;
}
int Car::get_wheels() const {
       return wheels;
}


Boat::Boat() : Vehicle() {}   
Boat::Boat(string make, int year) : Vehicle (make, year) {}  
Boat::~Boat() {}

void Boat::Display() const {
         cout << "Boat" << endl;
         Vehicle::Display();      
}


VehicleList::VehicleList() : head(nullptr) {}     // the LinkedList is empty (no Node) initially.
VehicleList::~VehicleList() {
    Vehicle * p_walker1 = head;
    Vehicle * p_walker2 = p_walker1;
    while (p_walker1 != nullptr) {
        p_walker2 = p_walker1;
        p_walker1 = p_walker1->get_next();
        delete p_walker2;
    }
}
void VehicleList::InsertFront(Vehicle * p_vehicle) {
    p_vehicle->set_next(head); // set next in vehicle object to point to whatever head is currently pointing to.
    head = p_vehicle;    // now set head to point to the new vehicle object.
}
void VehicleList::InsertEnd(Vehicle * p_vehicle) {
    Vehicle * p_walker = head;
    if (p_walker != nullptr) {
        while (p_walker->get_next() != nullptr) {
            p_walker = p_walker->get_next();
        }
        p_walker->set_next(p_vehicle);
    }
    else {
        head = p_vehicle;
    }
}
void VehicleList::RemoveFirst() {
    Vehicle * p_walker = head;
    if (p_walker != nullptr) {
        head = p_walker->get_next();
    } 
    delete p_walker;
}
void VehicleList::InsertSorted(Vehicle * p_vehicle) {
    Vehicle * p_walker1 = head;
    Vehicle * p_walker2 = p_walker1;
    if (p_walker1 != nullptr) {
        while (p_walker1->get_year() < p_vehicle->get_year()) {
            p_walker2 = p_walker1;
            p_walker1 = p_walker1->get_next();
        }
        p_walker2->set_next(p_vehicle);
    }
    else {
        head = p_vehicle;
    }
}
Vehicle * VehicleList::Search(string make, int year) const {
    Vehicle * p_walker = head;  // always use a local variable - never touch/use head to traverse the list.

    while (p_walker != nullptr) {   // p_walker currently points to some node.
        if (p_walker->get_make() == make && p_walker->get_year() == year) {
                return p_walker;    // found the first match.
        }
        p_walker = p_walker->get_next();    // move p_walker to point to the next node.
    }
    return nullptr;   // not found
}
void VehicleList::ShowList() const {
    Vehicle * p_walker = head;  
    while (p_walker != nullptr) {
        p_walker->Display();
        p_walker = p_walker->get_next();     // move to next node.
    }
}
int VehicleList::CountNodes() const {
    int count = 0;
    Vehicle * p_vehicle = head;
    while (p_vehicle != nullptr) {
        ++count;
        p_vehicle = p_vehicle->get_next();
    } 
    return count;
}
bool VehicleList::Empty() const {
    return head == nullptr;
}