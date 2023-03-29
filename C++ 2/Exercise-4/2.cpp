#include <iostream>

using namespace std;

class Phone {
    private:
        double price;
    protected:
        string phone_number;
    public:
        Phone();   // initialize phone_number to "1112223333",  price to 0.0
        Phone(double price, string phone_number) ;
        ~Phone();

        void Dial() ;
        void TurnOn();
};  

class SmartPhone : public Phone {
    private:
        int storage;
        string model;
    public:
        SmartPhone();
        SmartPhone(double price, string phone_number, int storage, string model);
        ~SmartPhone();

        void Dial();
};

int main() {
    const int kNPhone = 3;
    Phone * phone_list[kNPhone] = {nullptr};

    for (int i = 0; i < kNPhone; ++i) {
        phone_list[i] = new SmartPhone();
        phone_list[i]->TurnOn();
    }

    SmartPhone * p_smartphone = nullptr;
    p_smartphone = static_cast<SmartPhone *>(phone_list[kNPhone - 1]);
    p_smartphone->Dial();

    for (auto p_phone : phone_list) {
        p_smartphone = static_cast<SmartPhone *>(p_phone);
        delete p_smartphone;
    }

    return 0;
}

Phone::Phone() : price(3), phone_number("333") {}
Phone::Phone(double price, string phone_number) : price(price), phone_number(phone_number) {};
void Phone::Dial() {
    cout << "Phone number is " << phone_number << endl;
    cout << "Price is " << price << endl;
}
void Phone::TurnOn() {}

SmartPhone::SmartPhone() : Phone(), storage(3), model("abc") {}
SmartPhone::SmartPhone(double price, 
                       string phone_number, 
                       int storage, 
                       string model) : Phone(price, phone_number),
                                       storage(storage),
                                       model(model) {}
void SmartPhone::Dial() {
    Phone::Dial();
    cout << "smartdial" << endl;
}