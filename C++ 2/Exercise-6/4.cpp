#include <iostream>
#include <iomanip>

using namespace std;

class Exam {
    private:
        string exam_name;
        string questions[10];
        int * p_score;  // pointer to dynamic memory.
    public:
        Exam(const Exam & other);
};

int main() { 
}

Exam::Exam(const Exam & other) {
    this->exam_name = other.exam_name;
    this->p_score = new int(*(other.p_score));
    for (int i = 0; i < 10; ++i) {
        questions[i] = other.questions[i];
    }
}