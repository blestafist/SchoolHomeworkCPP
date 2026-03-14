#include <iostream>
#include <fstream>

// ============================================ CONFIGURATION ============================================

const std::string INPUT_FILE_NAME = "slowa.txt";
const std::string PASS_FILE_NAME = "hasla_b.txt";
const std::string ANSWERS_FILE_NAME = "slowa_b.txt";

// =======================================================================================================

bool IsPalindrome(const std::string& str, int len) {
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i]) { return false; }
    }

    return true;
}


std::string ComposeW2(const std::string& origin) {
    int w1Len = 1;

    for (int i = origin.size(); i >= 1; i--) {
        if (IsPalindrome(origin, i)) { w1Len = i; break; }
    }

    std::string result = "";
    for (int i = origin.size() - 1; i >= w1Len; i--) {
        result += origin[i];
    }

    return result;
}


int main() {
    std::ifstream inputFile (INPUT_FILE_NAME);
    if (!inputFile) { std::cerr << "Error while opening input file!"; return -1; }

    std::ofstream passFile (PASS_FILE_NAME), answersFile (ANSWERS_FILE_NAME);
    if (!passFile || !answersFile) { std::cerr << "Error while opening output files!"; return -1; }

    auto Print = [&] (auto&&... args) { (std::cout << ... << args) << "\n"; (answersFile << ... << args) << "\n"; };

    std::string tempWord, 
    longestStr = "",
    shortestStr = "",
    contains12Chars = "";

    int longest = -1,
    shortest = -1,
    sumLength = 0;

    while (inputFile >> tempWord) {
        std::string composed = ComposeW2(tempWord) + tempWord;
        int len = composed.size(); sumLength += len;

        std::cout << composed << "\n";
        passFile << composed << "\n";

        if (len == 12) { contains12Chars += composed + "\n"; }
        if (longest == -1 || len > longest) { longest = len; longestStr = composed; }
        if (shortest == -1 || len < shortest) { shortest = len; shortestStr = composed; }
    }

    std::cout << "\n\n";

    Print("Hasła o długości 12: \n", contains12Chars);
    Print("\nNajdłuższe hasło: ", longestStr);
    Print("Najkrótsze hasło: ", shortestStr);
    Print("\nSuma wszystkich długości: ", sumLength);

    return 0;
}