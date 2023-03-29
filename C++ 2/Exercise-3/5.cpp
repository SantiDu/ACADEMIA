#include <iostream>

using namespace std;

class eToy {
  public:
     void Play();
};

int main() {
    const int kNToy = 4096;
    eToy * toy_list[kNToy] = {nullptr};

    eToy ** p_p_toy = toy_list;
    for (int i = 0; i < kNToy; ++i) {
        *p_p_toy++ = new eToy;
    }

    p_p_toy = toy_list;
    for (int i = 0; i < kNToy; ++i) {
        (*p_p_toy++)->Play();
    }

    p_p_toy = toy_list;
    for (int i = 0; i < kNToy; ++i) {
        delete *p_p_toy++;
    }

    return 0;
}