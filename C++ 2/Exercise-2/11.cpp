#include <iostream>
#include <iomanip>

using namespace std;
class Person {
     public:
         static const int DEFAULT_AGE;
     private:
         string name;
         int age;
     public:
         Person();
         Person(string name, int age);
         bool CanVote() const;
};


int main () {
     const int kNPointers = 512000;
     Person * array_of_pointers[kNPointers] = {nullptr};
     string name;
     int age = 0;
     for (int i = 0; i < kNPointers; ++i) {
          getline(cin, name);
          array_of_pointers[i] = new Person(name, age);
     }
     for (int i = 0; i < kNPointers; ++i) {
          delete array_of_pointers[i];
          array_of_pointers[i] = nullptr;
     }
     return 0;
}

const int Person::DEFAULT_AGE = 0;
Person::Person() : age(Person::DEFAULT_AGE) {}   // why don't we need to initialize string name?
Person::Person(string name, int age) : name(name), age(age) {}

bool Person::CanVote() const {
    return  age >= 18;
}