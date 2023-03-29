#include <iostream>
#include <iomanip>

using namespace std;

class Fraction;

Fraction operator+ (const int left, const Fraction & right);
bool operator==(const Fraction & left, const Fraction & right);
class Fraction {
    private:
        double numerator;
        double denominator;
   public:
        Fraction();
        Fraction(double numerator,  double denominator);
        ~Fraction();
        Fraction operator+ (const Fraction & right) const;
        Fraction operator+ (const int & right) const;
        friend Fraction operator+ (const int left, const Fraction & right);
        friend bool operator==(const Fraction & left, const Fraction & right);
        // bool operator== (const Fraction & right) const; 
        bool operator!= (const Fraction & right) const; 
        void show() const;
};

int main() { 
    Fraction f = Fraction(2, 3);
    f.show();
    (f + 2).show();
    (3 + f).show();
    cout << (Fraction(3, 3) == f ? 'T' : 'F') << endl;
}

Fraction::Fraction() : numerator(0), denominator(1) {}
Fraction::Fraction(double numerator, double denominator) : numerator(numerator), denominator(denominator) {};
Fraction::~Fraction() {}
Fraction operator+ (const int left, const Fraction & right) {
    return Fraction(right.denominator * left + right.numerator, right.denominator);
}
Fraction Fraction::operator+(const int & right) const {
    return Fraction(numerator + right * denominator, denominator);
}
Fraction Fraction::operator+ (const Fraction & right) const {
    Fraction result;  // this is the resulted fraction from the addition to be returned.
    result.numerator = this->numerator * right.denominator + this->denominator * right.numerator;
    result.denominator = this->denominator * right.denominator;

    return result;
}
bool operator==(const Fraction & left, const Fraction & right) {
    return left.denominator * right.numerator == left.numerator * right.denominator;
}
// bool Fraction::operator== (const Fraction & right) const {
//     return (this->numerator * right.denominator == this->denominator * right.numerator);
// }
// bool Fraction::operator!= (const Fraction & right) const {
//     return !operator== (right);
// }
bool Fraction::operator!= (const Fraction & right) const {
    return !(*this == right);
}
void Fraction::show() const {
    cout << numerator << " / " << denominator << endl;
}