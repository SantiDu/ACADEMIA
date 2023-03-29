#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <vector>

int main() {
    std::map<std::string, std::vector<int>> classes_scores;
    std::map<std::string, std::vector<int>>::iterator cs2b_iter = classes_scores.find("CS 2B");
    
    if (cs2b_iter != classes_scores.end()) {
        std::vector<int>::iterator smallest_iter = cs2b_iter->second.begin();
        
        for (std::vector<int>::iterator iter = (cs2b_iter->second.begin() + 1); iter != cs2b_iter->second.end(); ++iter) {
            if ((*iter) < (*smallest_iter)) {
                smallest_iter = iter;
            }
        }
        
        cs2b_iter->second.erase(smallest_iter);
    }
    
    return 0;
}