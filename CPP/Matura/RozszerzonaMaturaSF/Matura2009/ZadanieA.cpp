#include <iostream>
#include <fstream>

// =========================== CONFIGURATION ===========================

const std::string INPUT_FILE_NAME = "dane.txt";
const std::string OUTPUT_FILE_NAME = "zad_5.txt";

// =====================================================================

bool IsPalindrome(const std::string& str) {
    for (size_t i = 0; i < str.size() / 2; i++) {
        if (str[i] != str[str.size() - 1 - i]) { return false; }
    }

    return true;
}

int main() {
    std::ifstream inputFile(INPUT_FILE_NAME);
    std::ofstream outputFile(OUTPUT_FILE_NAME);
    
    std::string tempWord;
    int palindromeCount = 0;
    
    while (inputFile >> tempWord) {
        if (IsPalindrome(tempWord)) { palindromeCount++; }
    }
    
    std::cout << "a) " << palindromeCount << "\n";
    outputFile << "a) " << palindromeCount << "\n";
    
    return 0;
}
