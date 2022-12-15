#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void InitializeScores(int m_score[], int scores_size);
void PrintScores(int * m_scores, int scores_size);
double GetScoresAverage(int * m_scores, int scores_size);

int main() {
    const int kMaxScores = 32;
    int scores[kMaxScores] = {0};

    srand(static_cast <unsigned int> (time(NULL)));

    InitializeScores(scores, kMaxScores);
    PrintScores(scores, kMaxScores);
    cout << GetScoresAverage(scores, kMaxScores) << endl;

    return 0;
}

void InitializeScores(int * m_scores, int scores_size) {
    int random_score = 0;
    
    for (int i = 0; i < scores_size; ++i) {
        random_score = 70 + rand() % 31;
        m_scores[i] = random_score;
    }
}

void PrintScores(int * m_scores, int scores_size) {
    for (int i = 0; i < scores_size; ++i) {
        cout << setw(3) << m_scores[i] << endl;
    }
}

double GetScoresAverage(int * m_scores, int scores_size) {
    double sum = 0.0;
    for (int i = 0; i < scores_size; ++i) {
        sum += m_scores[i];
    }
    return sum / scores_size;
}