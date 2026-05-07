#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>


// ======================= CONFIGURATION =======================

const std::string INPUT_FILE = "anagram.txt";

const std::string OUTPUT_FILE_A = "odp_4a.txt";
const std::string OUTPUT_FILE_B = "odp_4b.txt";

// =============================================================

bool SameLength(const std::vector<std::string>& vec) {
    for (char i = 1; i < 5; i++) { if (vec[i].size() != vec[0].size()) { return false; } }
    return true;
}

bool AllAnagramFirst(std::vector<std::string> vec) {
    for (char i = 0; i < 5; i++) { 
        std::sort(vec[i].begin(), vec[i].end()); 
        if (i > 0 && vec[i] != vec[0]) { return false; }
    }

    return true;
}

std::string MergeLine(const std::vector<std::string>& vec) {
    std::string result = "";

    for (char i = 0; i < 5; i++) {
        result += vec[i] + " ";
    }

    return result;
}

int main() {
    std::ifstream inputFile(INPUT_FILE);
    std::ofstream outputFileA(OUTPUT_FILE_A), outputFileB(OUTPUT_FILE_B);

    std::string tempWord;
    char tempLength;

    std::vector<std::string> line, sameLengthList, allAnagramList;

    while (inputFile >> tempWord) {
        if (line.size() == 5) { if (SameLength(line)) { sameLengthList.push_back(MergeLine(line)); if (AllAnagramFirst(line)) { allAnagramList.push_back(MergeLine(line)); } } line.clear(); }

        line.push_back(tempWord);
    }

    std::cout << "1. \n\n";
    for ( auto s : sameLengthList ) { std::cout << s << "\n"; }

    std::cout << "\n\n2. \n\n";
    for ( auto s : allAnagramList ) { std::cout << s << "\n"; }
    
    return 0;
}