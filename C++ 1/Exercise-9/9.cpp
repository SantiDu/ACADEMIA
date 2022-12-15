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

int BinarySearch(Student arr[], int start_pos, int end_pos, string name);
int RecursiveBinarySearch ( int list [], int first_index, int last_index, int target );

int main() {
    Student arr[] = {Student("abc"), Student("bbc"), Student("cbc")};
    cout << BinarySearch(arr, 0, 2, "dbc") << endl;
    return 0;
}

Student::Student() {}
Student::Student(string student_name) : last_name(student_name) {}
Student::~Student() {}
string Student::get_last_name() const {return last_name;}

int BinarySearch(Student arr[], int start_pos, int end_pos, string name) {
    int middle_pos = 0;
    int compare = 0;

    if (start_pos > end_pos) {
        return -1;
    }

    middle_pos = (start_pos + end_pos) / 2; 
    compare = arr[middle_pos].get_last_name().compare(name);

    if (compare > 0) {
        return BinarySearch(arr, start_pos, middle_pos - 1, name);
    }
    else if (compare < 0) {
        return BinarySearch(arr, middle_pos + 1, end_pos, name);
    }
    else {
        return middle_pos;
    }
}