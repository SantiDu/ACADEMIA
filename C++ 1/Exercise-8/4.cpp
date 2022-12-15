#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Fruit {
    private:
        string name;
        float weight;
    public:
        Fruit();
        Fruit(string fruit_name, float fruit_weight);

        void set_fruit_name(string fruit_name);
        void set_fruit_weight(double fruit_weight);
        void PrepareFruit();
};

void UpdateFruit(Fruit & fruit, string fruit_name, double fruit_weight) {
    fruit.set_fruit_name(fruit_name);
    fruit.set_fruit_weight(fruit_weight);
}

int main() {
    int kNFruits = 2;
    Fruit fruits[kNFruits];

    string name;
    double weight = 0.0;

    for (int i = 0; i < kNFruits; ++i) {
        cout << "name: ";
        if (cin.peek() == '\n') {
            cin.ignore();
        }
        getline(cin, name);
        cout << "weight: ";
        cin >> weight;

        fruits[i] = Fruit(name, weight);
    }

    UpdateFruit(fruits[0], "ccc", 3);

    for (int i = 0; i < kNFruits; ++i) {
        fruits[i].PrepareFruit();
    }

    return 0;
}

Fruit::Fruit() {};
Fruit::Fruit(string fruit_name, float fruit_weight): name(fruit_name), weight(fruit_weight) {};

void Fruit::set_fruit_name(string fruit_name) {
    name = fruit_name;
}

void Fruit::set_fruit_weight(double fruit_weight) {
    weight = fruit_weight;
}

void Fruit::PrepareFruit() {
    cout << "name: " << name << endl;
    cout << "weight: " << weight << endl;
}