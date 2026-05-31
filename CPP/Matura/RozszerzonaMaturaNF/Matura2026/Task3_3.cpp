#include <iostream>
#include <fstream>
#include <string>

// ================================== CONFIGURATION ==================================

const std::string INPUT_FILE_NAME = "pary_przyklad.txt";
const std::string OUTPUT_FILE_NAME = "wyniki3.txt";

// ===================================================================================

size_t LongestPrefixSuffix(const std::string& str1, const std::string& str2) {
    for (size_t i = std::min(str1.size(), str2.size()); i >= 5; i--) {
        std::string overlapFirst = str1.substr(str1.size() - i);
        std::string overlapSecond = str2.substr(0, i);

        if (overlapFirst == overlapSecond) { return i; }
    }

    return 0;
}

int main() {
    std::ifstream inputFile (INPUT_FILE_NAME);
    if (!inputFile) { std::cerr << "Error while opening input file!"; return 1; }

    std::ofstream outputFile (OUTPUT_FILE_NAME);

    std::string word1, word2;

    while (inputFile >> word1 >> word2) {
        size_t res = std::max(LongestPrefixSuffix(word1, word2), LongestPrefixSuffix(word2, word1));

        if (res >= 5) { std::cout << word1 << ' ' << word2 << ' ' << res << '\n'; }
    }

	return 0;
}
