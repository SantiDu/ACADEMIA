#include <iostream>
#include <iomanip>

using namespace std;

class ParseException : public exception {
    private:
        bool rethrow;
    public: 
        ParseException();
        bool get_rethrow() const;
        void set_rethrow(bool rethrow);
        virtual const char * what() const noexcept;
};

int main() {
    try {
        try {
            throw ParseException();
        }
        catch (ParseException & e) {
            cout << e.what() << endl;
            // if unable to resolve parse error:
            e.set_rethrow(true);
            if (e.get_rethrow()) {
                throw;
            }
        }  
    }
    catch (ParseException & e) {
        cout << "unable to resolve parse error" << endl;
    }
    return 0;
}

ParseException::ParseException() : rethrow(false) {}
bool ParseException::get_rethrow() const {
    return rethrow;
}
void ParseException::set_rethrow(bool rethrow) {
    this->rethrow = rethrow;
}
const char * ParseException::what() const noexcept {
    return "Failed to parse!";
}