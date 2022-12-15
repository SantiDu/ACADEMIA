#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Book {
    private:
        string title;
    public:
        Book();
        Book(string book_title);
        ~Book();
        string get_title() const;
};

void BubbleSort(Book arr[], unsigned int size);

int main() {
    unsigned int kNElem = 3;
    Book arr[kNElem] = {Book("bbc"), Book("cbc"), Book("abc")};
    BubbleSort(arr, kNElem);
    for (int i = 0; i < kNElem; ++i) {
        cout << arr[i].get_title() << endl;
    }
    return 0;
}

void BubbleSort(Book arr[], unsigned int size) {
    bool swapped = true;
    Book temp;

    while (swapped) {
        swapped = false;
        for (int i = 1; i < size; ++i) {
            if (arr[i - 1].get_title().compare(arr[i].get_title()) < 0) {
                temp = arr[i - 1];
                arr[i - 1] = arr[i];
                arr[i] = temp;
                swapped = true;
            }
        }
    }
}

Book::Book() {}
Book::Book(string book_title): title(book_title) {}
Book::~Book() {}
string Book::get_title() const {return title;}