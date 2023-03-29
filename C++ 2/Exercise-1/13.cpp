#include <iostream>
#include <iomanip>

using namespace std;

class Fruit {
   private:
      string name;
      float weight;
   public:
      Fruit();
      Fruit(string fruit_name, float fruit_weight);
               
      void set_fruit_name(string name);
      void set_fruit_weight(double weight);
      void PrepareFruit();
};

int main () {
     string name;
     float weight = 0.0f;
     const int kNFruits = 128;
     Fruit fruits[kNFruits];
     for (int i = 0; i < kNFruits; ++i) {
          fruits[i].set_fruit_name(name);
          fruits[i].set_fruit_weight(weight);
     }
     for (int i = 0; i < kNFruits; ++i) {
          fruits[i].PrepareFruit();
     }
     return 0;
}