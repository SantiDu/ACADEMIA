#include <iostream>
#include <iomanip>

using namespace std;

class Animal {
    public:
        virtual ~Animal();
        virtual void Eat();
        virtual void Drink();
};

class Zebra : public Animal {
    public:
        void NibbleHair();    // specific to Zebra only.
};

class Elephant : public Animal {
    public:
        void Grumbling();    // specific to Zebra only.
};

class Tiger : public Animal {
    public:
        void Hunt();    // specific to Zebra only.
};

class Panda : public Animal {
    public:
        void JustSleep();    // specific to Zebra only.
};

int main() {
    const int kAnimalMax = 4;
    Animal * zoo[kAnimalMax] = {nullptr};

    // initialize the zoo list;

    Zebra * p_zebra = nullptr;
    Elephant * p_elephant = nullptr;
    Tiger * p_tiger = nullptr;
    Panda * p_panda  = nullptr;

    for (auto & p_animal : zoo) {
        p_animal->Eat();
        p_animal->Drink();

        if ((p_zebra = dynamic_cast<Zebra *>(p_animal)) != nullptr) {
            p_zebra->NibbleHair();
        }
        else if ((p_elephant = dynamic_cast<Elephant *>(p_animal)) != nullptr) {
            p_elephant->Grumbling();
        }
        else if ((p_tiger = dynamic_cast<Tiger *>(p_animal)) != nullptr) {
            p_tiger->Hunt();
        }
        else if ((p_panda = dynamic_cast<Panda *>(p_animal)) != nullptr) {
            p_panda->JustSleep();
        }
    }

    return 0;
}