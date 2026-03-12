#include <fstream>
#include <iostream>

// ================================== CONFIGURATION ==================================

const std::string INPUT_FILE_NAME   = "slowa.txt";
const std::string OUTPUT_FILE_NAME  = "hasla_b.txt";
const std::string OUTPUT2_FILE_NAME = "slowa_b.txt";

// ===================================================================================

bool IsPalindrome(const std::string& str, int len) {
    for (int i = 0; i < len / 2; i++)
        if (str[i] != str[len - 1 - i]) { return false; };
    return true;
}

std::string ReturnW2(const std::string& str) {
    int w1Len = 1;
    for (int len = str.size(); len >= 1; len--) {
        if (IsPalindrome(str, len)) { w1Len = len; break; }
    }
    std::string reversed = "";
    for (int i = str.size() - 1; i >= w1Len; i--) { reversed += str[i]; }

    return reversed;
}

int main() {
    std::ifstream inputFile(INPUT_FILE_NAME);
    if (!inputFile) { std::cerr << "Error opening input file!\n"; return -1; }

    std::ofstream outputFilePass(OUTPUT_FILE_NAME), outputFileWords(OUTPUT2_FILE_NAME);
    if (!outputFilePass || !outputFileWords) { std::cerr << "Error opening output file!\n"; return -1; }

    auto PrintWords = [&](auto&&... args) { (std::cout << ... << args) << "\n"; (outputFileWords << ... << args) << "\n"; };

    std::string tempWord, wordModified;
    std::string shortestStr = "", longestStr = "", contains12Chars = "";
    int sumOfLength = 0, minLength = -1, maxLength = -1;

    while (inputFile >> tempWord) {
        wordModified = ReturnW2(tempWord) + tempWord;
        std::cout << wordModified << '\n';
        outputFilePass << wordModified << '\n';

        int len = wordModified.size();
        sumOfLength += len;

        if (len == 12) { contains12Chars += wordModified + "\n"; }
        if (minLength == -1 || len < minLength) { minLength = len; shortestStr = wordModified; }
        if (maxLength == -1 || len > maxLength) { maxLength = len; longestStr  = wordModified; }
    }

    PrintWords("1. Hasla o dlugosci 12:\n", contains12Chars);
    PrintWords("2. Najdluzsze haslo: ",     longestStr);
    PrintWords("   Najkrotsze haslo: ",     shortestStr);
    PrintWords("3. Suma dlugosci hasel: ",  sumOfLength);

    return 0;
}