#include <iostream>
#include <fstream>

// =========================== CONFIGURATION ===========================

const std::string INPUT_FILE = "dane.txt";
const std::string OUTPUT_FILE = "zad_5.txt";

// =====================================================================

bool IsPalindrome(const std::string& word) {
    for (size_t i = 0; i < word.size() / 2; i++) {
        if (word[i] != word[word.size() - 1 - i]) { return false; }
    }
    return true;
}

int main() {
    std::ifstream inputFile(INPUT_FILE);
    std::ofstream outputFile(OUTPUT_FILE);
    
    std::string word;
    int palindromeCount = 0;
    
    while (inputFile >> word) {
        if (IsPalindrome(word)) { palindromeCount++; }
    }
    
    outputFile << "a) " << palindromeCount << "\n";
    
    return 0;
}
