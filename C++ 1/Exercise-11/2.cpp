#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Book  {
    public:
        void UpdatePrice(float percent);
};

int main() {
    Book book_collection[1024];

    for (Book &book : book_collection) {
        book.UpdatePrice(0.05);
    }
    return 0;
}