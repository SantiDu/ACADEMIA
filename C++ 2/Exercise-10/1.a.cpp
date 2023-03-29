#include <iostream>
#include <iomanip>
#include <map>

using namespace std;

class Book {
    public:
        int x;
        Book();
        Book(int x);
};

void Copy(const map<string, Book> &, map<string, Book> &);
void Show(const map<string, Book> &);

int main() {
    map<string, Book> map1;
    map<string, Book> map2;
    map1["a"] = Book(1);
    map1["b"] = Book(2);
    Copy(map1, map2);
    map1["a"].x = 2;
    Show(map1);
    Show(map2);
    return 0;
}

void Copy(const map<string, Book> & source, map<string, Book> & destination) {
    map<string, Book>::const_iterator iter;
    destination.clear();
    for (iter = source.begin(); iter != source.end(); ++iter) {
        destination.insert(*iter);
    }
}

Book::Book() {}
Book::Book(int x) : x(x) {}

void Show(const map<string, Book> & a_map) {
    map<string, Book>::const_iterator iter;
    for (iter = a_map.begin(); iter != a_map.end(); ++iter) {
        cout << iter->second.x << endl;
    }
}