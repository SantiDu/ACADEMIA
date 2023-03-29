#include <iostream>
#include <iomanip>

using namespace std;

class Student {
   private:
      string last_name;
      string first_name;

   public:
      Student ();
      Student ( string last_name, string first_name);
      ~Student ();

      string get_last_name () const;      
};

int main () {
     Student student("Anderson", "Frank");
     Student * p_student = nullptr;
     p_student = &student;
     p_student->get_last_name();
     return 0;
}