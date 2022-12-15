#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Course {
    private:
        string course_title;
        int CRN;
        string course_section;
        bool online;
        double total_units;
        string instructor_name;
        int seats_available;
    public:
        static const string DEFAULT_COURSE_TITLE;
        static const int DEFAULT_CRN;
        static const string DEFAULT_COURSE_SECTION;
        static const bool DEFAULT_ONLINE;
        static const double DEFAULT_TOTAL_UNITS;
        static const string DEFAULT_INSTRUCTOR_NAME;
        static const int DEFAULT_SEATS_AVAILABLE;
    public:
        Course();
        Course(string title, int crn, string section, bool is_online, double units, string instructor, int seats);
        ~Course();
    public:
        string get_course_title() const;
        void set_course_title(string title);
        int get_CRN() const;
        void set_CRN(int crn);
        string get_course_section() const;
        void set_course_section(string section);
        bool get_online() const;
        void set_online(bool is_online);
        double get_total_units() const;
        void set_total_units(double units);
        string get_instructor_name() const;
        void set_instructor_name(string instructor);
        int get_seats_available() const;
        void set_seats_available(int seats);
    public:
        bool IsFull() const;
        bool Enroll();
        void Listing() const;
};

void BuildScheduleOfClasses(Course course_list[], int course_count);
void ViewScheduleOfClasses(Course course_list[], int course_count);
void ViewCourseSections(Course course_list[], int course_count);

int main() {
    int kNCourses = 10;
    Course courses[kNCourses];

    BuildScheduleOfClasses(courses, kNCourses);
    ViewScheduleOfClasses(courses, kNCourses);
    ViewCourseSections(courses, kNCourses);

    return 0;
}

const string Course::DEFAULT_COURSE_TITLE = "TBD";
const int Course::DEFAULT_CRN = 0;
const string Course::DEFAULT_COURSE_SECTION = "0Z";
const bool Course::DEFAULT_ONLINE = true;
const double Course::DEFAULT_TOTAL_UNITS = 5.0;
const string Course::DEFAULT_INSTRUCTOR_NAME = "Staff";
const int Course::DEFAULT_SEATS_AVAILABLE = 40;

Course::Course() : course_title(Course::DEFAULT_COURSE_TITLE),
                   CRN(Course::DEFAULT_CRN),
                   course_section(Course::DEFAULT_COURSE_SECTION),
                   online(Course::DEFAULT_ONLINE),
                   total_units(Course::DEFAULT_TOTAL_UNITS),
                   instructor_name(Course::DEFAULT_INSTRUCTOR_NAME),
                   seats_available(Course::DEFAULT_SEATS_AVAILABLE) {}
Course::Course(string title, int crn, string section, bool is_online, double units, string instructor, int seats) :
                    course_title(title),
                    CRN(crn),
                    course_section(section),
                    online(is_online),
                    total_units(units),
                    instructor_name(instructor),
                    seats_available(seats) {}
Course::~Course() {
    cout << "Course " << course_title << '-' << course_section << " dtor called …\n";
}

string Course::get_course_title() const {return course_title;}
void Course::set_course_title(string title) {course_title = title;}
int Course::get_CRN() const {return CRN;}
void Course::set_CRN(int crn) {CRN = crn;}
string Course::get_course_section() const {return course_section;}
void Course::set_course_section(string section) {course_section = section;}
bool Course::get_online() const {return online;}
void Course::set_online(bool is_online) {online = is_online;}
double Course::get_total_units() const {return total_units;}
void Course::set_total_units(double units) {total_units = units;}
string Course::get_instructor_name() const {return instructor_name;}
void Course::set_instructor_name(string instructor) {instructor_name = instructor;}
int Course::get_seats_available() const {return seats_available;}
void Course::set_seats_available(int seats) {seats_available = seats;}

bool Course::IsFull() const {
    return seats_available <= 0;
}

bool Course::Enroll() {
    if (seats_available > 0) {
        --seats_available;
        return true;
    }
    else {
        return false;
    }
}

void Course::Listing() const {
    cout << right;
    cout << setw(20) << "Course title: " << course_title << endl;
    cout << setw(20) << "CRN: " << CRN << endl;
    cout << setw(20) << "Course section: " << course_section << endl;
    cout << setw(20) << "Online: " << online << endl;
    cout << setw(20) << "Total units: " << total_units << endl;
    cout << setw(20) << "Instructor name: " << instructor_name << endl;
    cout << setw(20) << "Seats available: " << seats_available << endl;
    cout << endl;
}

void BuildScheduleOfClasses(Course course_list[], int course_count) {
    const int kArraySize = 10;
   
    string course_title_list[kArraySize] = {"CS 2B", "CS 1A", "CS 3B", "CS 1B", "CS 1C", "CS 2C", "CS 30A", "CS 2A", "CS 1A", "CS 1B"};
    int course_CRN_list[kArraySize] = {30267, 30196, 30720, 30710, 30307, 30308, 30231, 30197, 30478, 30414};
    string course_section_list[kArraySize] = {"1W", "1Y", "1Z", "3Y", "1W", "1W", "1W", "1Z", "3W", "2W"};
    string instructor_list[kArraySize] = {"Venkataraman", "Weusijana", "Yang", "Mazloom", "Mazloom", "Lai", "Murphy", "Venkataraman", "Meade", "Krishnamurthy"};
   
    for (int i = 0; i < course_count; ++i) {           
        if (i % 2 == 0) {
            course_list[i] = Course(course_title_list[i], 
                                    course_CRN_list[i], 
                                    course_section_list[i], 
                                    Course::DEFAULT_ONLINE, 
                                    Course::DEFAULT_TOTAL_UNITS,
                                    instructor_list[i],
                                    Course::DEFAULT_SEATS_AVAILABLE);
        }
        else {
            course_list[i].set_course_title(course_title_list[i]);
            course_list[i].set_CRN(course_CRN_list[i]);
            course_list[i].set_course_section(course_section_list[i]);
            course_list[i].set_online(Course::DEFAULT_ONLINE);
            course_list[i].set_total_units(Course::DEFAULT_TOTAL_UNITS);
            course_list[i].set_instructor_name(instructor_list[i]);
            course_list[i].set_seats_available(Course::DEFAULT_SEATS_AVAILABLE);
        }
    }
}

void ViewScheduleOfClasses(Course course_list[], int course_count) {
    for (int i = 0; i < course_count; ++i) {
        course_list[i].Listing();
    }
}

void ViewCourseSections(Course course_list[], int course_count) {
    string title;
    bool found = false;

    cout << "Please enter a course title: ";
    if (cin.peek() == '\n') {
        cin.ignore();
    }
    getline(cin, title);

    for (int i = 0; i < course_count; ++i) {
        if (course_list[i].get_course_title() == title) {
            found = true;
            cout << "\t\tCourse Found" << endl;
            if (course_list[i].IsFull()) {
                cout << "\t\t*FULL*" << endl;
            }
            course_list[i].Listing();
        }
    }

    if (!found) {
        cout << "Sorry " << title << "course is not offered this quarter!" << endl << endl;
    }
}