#include <iostream>

using namespace std;

class eToy {
  public:
     void Play();
};

int main() {
    const int kNToy = 4096;
    eToy * const toy_list = new eToy[kNToy];    

    eToy * p_toy = toy_list;
    for (int i = 0; i < kNToy; ++i) {
        (*p_toy++).Play();
    }

    delete[] toy_list;

    return 0;
}