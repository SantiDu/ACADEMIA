#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Vehicle;
class Insurer;
class PoliceReport;

int GlobalFunction(Vehicle & vehicle, Insurer & insurer, PoliceReport & police_report);

class Vehicle {
    private:
        int a;
        friend int GlobalFunction(Vehicle & vehicle, Insurer & insurer, PoliceReport & police_report);
    public:
        Vehicle();
};

class Insurer {
    private:
        friend int GlobalFunction(Vehicle & vehicle, Insurer & insurer, PoliceReport & police_report);
    public:
        Insurer();
};

class PoliceReport {
    private:
        friend int GlobalFunction(Vehicle & vehicle, Insurer & insurer, PoliceReport & police_report);
    public:
        PoliceReport();
};


int main() {
    Vehicle v;
    Insurer i;
    PoliceReport pr;
    cout << GlobalFunction(v, i, pr) << endl;
    return 0;
}


Vehicle::Vehicle():a(1){}
Insurer::Insurer(){}
PoliceReport::PoliceReport(){}

int GlobalFunction(Vehicle & vehicle, Insurer & insurer, PoliceReport & police_report) {
    return vehicle.a;
}