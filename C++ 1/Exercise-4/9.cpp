#include <iostream>
#include <iomanip>

using namespace std;

double LetterGradeToGPA(char letter);

int main() {
      char letter_grade = '\0';
      double gpa = 0.0;

      cin >> letter_grade;
      gpa = LetterGradeToGPA(letter_grade);
      cout << gpa << endl;

      return 0;
}

double LetterGradeToGPA(char letter) {
      switch (letter) {
            case 'a':
            case 'A':
                  return 4.0;
            case 'b':
            case 'B':
                  return 3.0;
            case 'c':
            case 'C':
                  return 2.0;
            case 'd':
            case 'D':
                  return 1.0;
            default:
                  return 0.0;
      }
}