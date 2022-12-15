#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Student {
    private:
        string last_name;
    public:
        Student();
        Student(string last_name);
        ~Student();
        string get_last_name() const;
};

int main() {
    Student student("Anderson");
    Student * p_student = nullptr;
    p_student = &student;
    cout << p_student->get_last_name();
    return 0;
}

Student::Student() {}
Student::Student(string last_name) : last_name(last_name) {}
Student::~Student() {}
string Student::get_last_name() const {return last_name;}