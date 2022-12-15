#include <iostream>
#include <iomanip>

using namespace std;

class Exam {
    private:
        int duration;
        int score;
    public:
        Exam();
        Exam(int m_duration, int m_score);
};

int main() {
    return 0;
}

Exam::Exam():duration(60),score(0) {}

Exam::Exam(int m_duration, int m_score):duration(m_duration),score(m_score) {}
