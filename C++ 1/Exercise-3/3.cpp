#include <iostream>
#include <iomanip>

using namespace std;

int main() {
      string student_last_name;
      string student_first_name;
      string student_id;
      string student_gpa;
      string total_units;
      int student_id_i = 0;
      float student_gpa_f = 0.0f;
      int total_units_i = 0;

      getline(cin, student_last_name, ';');
      getline(cin, student_first_name, ';');
      getline(cin, student_id, ';');
      getline(cin, student_gpa, ';');
      getline(cin, total_units, ';');

      istringstream iss;
      iss.clear();
      iss.str(student_id);
      iss >> student_id_i;
      iss.clear();
      iss.str(student_gpa);
      iss >> student_gpa;
      iss.clear();
      iss.str(total_units);
      iss >> total_units;

      cout << "Name: " << student_first_name << ", " << student_last_name << endl;
      cout << "ID: " << student_id << endl;
      cout << "GPA: " << student_gpa << endl;
      cout << "Total Units: " << total_units << endl;

      return 0;
}