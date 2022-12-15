#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
      string quarter = "Fall";
      int year = 2020;
      string course = "CS 2A";
      string description = "\t\t";

      description += course;
      description += " ### ";
      description += quarter; 
      description += " " + to_string(year);
      description += " ### \t\t\n";

      cout << description;
      return 0;
}
