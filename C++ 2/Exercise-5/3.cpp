#include <iostream>
#include <iomanip>

using namespace std;

class Mail {
    private:
        string sender;
        string receiver;
        string content;
    public:
        Mail();
        Mail(string sender, string receiver, string content);
        virtual ~Mail();
        virtual bool Send() = 0;
        virtual double Cost() = 0;

};

int main() {

    return 0;
}