#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

class Student {
    public:
        int get_id() const;
        double get_gpa() const;
};

int main() {
    vector<Student *> students;
    vector<Student *>::iterator iter;
    for (iter = students.begin(); iter != students.end(); ++iter) {
        if ((*iter)->get_id() == 22003311) {
            cout << (*iter)->get_gpa() << endl;
            break;
        }
    }
    for (iter = students.begin(); iter != students.end(); ++iter) {
        delete *iter;
    }
    students.clear();

    return 0;
}