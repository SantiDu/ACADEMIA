#include <iostream>
#include <iomanip>

using namespace std;

class Phone {
    public:
        ~Phone() {cout << "phone destruct" << endl;}
        void Dial() {cout << "phone dial" << endl;};   
};

class SmartPhone : public Phone {
    public:
        ~SmartPhone() {cout << "smartphone destruct" << endl;}
        void Dial() {cout << "smartphone dial" << endl;}
        void DownloadApp();
};

class LandPhone : public Phone {
    public:
        ~LandPhone() {cout << "landphone destruct" << endl;}
        void Dial() {cout << "landphone dial" << endl;};
        void RingTone() {cout << "ringtone dial" << endl;}
};

int main() {
    Phone * p_phone = new SmartPhone;
    p_phone->Dial();
    SmartPhone * p_smart_phone = static_cast<SmartPhone *>(p_phone);
    p_smart_phone->DownloadApp();
    delete p_smart_phone;
    p_smart_phone = nullptr;

    Phone * p_phone2 = nullptr;
    p_phone2 = new LandPhone;
    // p_smart_phone = dynamic_cast<SmartPhone *>(p_phone);
    // if (p_smart_phone != nullptr) {
        // p_smart_phone->DownloadApp();
    // }
    p_smart_phone = static_cast<SmartPhone *>(p_phone2);
    p_smart_phone->DownloadApp();
    delete p_smart_phone;
    delete static_cast<LandPhone *>(p_phone2);
    return 0;
}

void SmartPhone::DownloadApp() {cout << "...downloading..." << endl;}