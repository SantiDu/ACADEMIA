#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <vector>

using std::string;
using std::map;
using std::vector;

int main() {
    map<string, vector<int>> classes_scores;
    auto iter = classes_scores.find("CS 2B");
    if (iter != classes_scores.end()) {
        for (auto iter_vec = iter->second.begin(); iter_vec != iter->second.end(); ++iter_vec) {
            if (*iter_vec == 40) {
                iter->second.erase(iter_vec);
                break;    
            }
        }
    } 
    return 0;
}