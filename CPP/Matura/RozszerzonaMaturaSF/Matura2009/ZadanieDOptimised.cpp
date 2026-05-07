#include <iostream>
#include <fstream>
#include <string>

// =========================== CONFIGURATION ===========================

const std::string INPUT_FILE_NAME = "dane.txt";
const std::string OUTPUT_FILE_NAME = "slowa.txt";

// =====================================================================

std::string GetMergedWord(const std::string& firstWord, const std::string& secondWord) {
    if (firstWord.find(secondWord) != std::string::npos) { return firstWord; }

    for (size_t i = std::min(firstWord.size(), secondWord.size()); i > 0; i--) {
        if (firstWord.substr(firstWord.size() - i) == secondWord.substr(0, i)) { 
            return firstWord + secondWord.substr(i);
        }
    }

    return firstWord + secondWord;
}

int main() {
    std::ifstream inputFile (INPUT_FILE_NAME);
    std::ofstream outputFile (OUTPUT_FILE_NAME);
    if (!inputFile) { std::cerr << "Error while opening input file!"; return -1; }

    std::string firstWord, secondWord;
    auto Print = [&] (auto&&... args) { (std::cout << ... << args) << "\n"; (outputFile << ... << args) << "\n"; };

    while (inputFile >> firstWord >> secondWord) {
        std::string resultAB = GetMergedWord(firstWord, secondWord), resultBA = GetMergedWord(secondWord, firstWord);        
        Print(resultAB.size() <= resultBA.size() ? resultAB : resultBA);
    }

    return 0;
}
