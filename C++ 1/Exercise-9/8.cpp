#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Student {
    private:
        string last_name;
    public:
        Student();
        Student(string student_name);
        ~Student();
        string get_last_name() const;
};

int BinarySearch(Student arr[], int size, string name);

int main() {
    Student arr[] = {Student("abc"), Student("bbc"), Student("cbc")};
    cout << BinarySearch(arr, 3, "dbc") << endl;
    return 0;
}

Student::Student() {}
Student::Student(string student_name) : last_name(student_name) {}
Student::~Student() {}
string Student::get_last_name() const {return last_name;}

int BinarySearch(Student arr[], int size, string name) {
    int start_pos = 0;
    int end_pos = size - 1;
    int middle_pos = 0;
    int compare = 0;

    while (start_pos <= end_pos) {
        middle_pos = (start_pos + end_pos) / 2;
        compare = arr[middle_pos].get_last_name().compare(name);
        if (compare == 0) {
            return middle_pos;
        }
        else if (compare < 0) {
            start_pos = middle_pos + 1;
        }
        else {
            end_pos = middle_pos - 1;
        }
    }

    return -1;
}