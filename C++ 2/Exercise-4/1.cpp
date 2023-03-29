#include <iostream>

using namespace std;

class Toy {
    private:
        int year;
    protected:
        double price;
    public:
        void Return() ;
};

class SuperUltimateGaragePlaySet : public Toy {
    public:
        void Play();
        void Return(); // re-defined member function.
};

int main() {
    Toy toy;

    toy.year = 2022;
    toy.price = 129.99;
    toy.Return();
    toy.Play();

    SuperUltimateGaragePlaySet  playset;
    playset.year = 2019;
    playset.price = 129.99;

    toy.Return();           // Is it Toy::Return or SuperUltimateGaragePlaySet::Return?
    playset.Return();   // Is it Toy::Return or SuperUltimateGaragePlaySet::Return?
    playset.Play();     // Is it Toy::Play or SuperUltimateGaragePlaySet::Play?

    return 0;
}
