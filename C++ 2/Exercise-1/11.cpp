#include <iostream>
#include <iomanip>

using namespace std;

class Exam {
   private:
     int duration;
     int score;
   public:
     Exam();
     Exam(int duration, int score);
     ~Exam();
     static const int DEFAULT_DURATION;
     static const int DEFAULT_SCORE;
};

int main () {
     return 0;
}

const int Exam::DEFAULT_DURATION = 60;
const int Exam::DEFAULT_SCORE = 0;
Exam::Exam() : duration(Exam::DEFAULT_DURATION), score(Exam::DEFAULT_SCORE) {}
Exam::Exam(int duration, int score) : duration(duration), score(score) {}
Exam::~Exam() {}