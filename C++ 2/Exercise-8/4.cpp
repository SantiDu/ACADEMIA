#include <iostream>
#include <iomanip>

using namespace std;

template <typename Key, typename Value>
class Pair {
    private:
        Key key;
        Value value;
    public:
        Key get_key() const;
        void set_key(Key key);
        Value get_value() const;
        void set_value(Value value);
};

int main() {
    return 0;
}

template <typename Key, typename Value>
Key Pair<Key, Value>::get_key() const {return key};
template <typename Key, typename Value>
void Pair<Key, Value>::set_key(Key key) {this->key = key;}
template <typename Key, typename Value>
Value Pair<Key, Value>::get_value() const {return value};
template <typename Key, typename Value>
void Pair<Key, Value>::set_value(Value value) {this->value = value;}

