#include <fstream>
#include <iostream>

/*

1. Pull the word from the file
2. Reverse the word, write it to output file
3. Measure its length
4. If needed. override the shortest and longest var
5. Close the file
6. Print results

*/

// ================================== CONFIGURATION ==================================

const std::string INPUT_FILE_NAME = "slowa.txt";
const std::string OUTPUT_FILE_NAME = "hasla_a.txt";
const std::string OUTPUT2_FILE_NAME = "slowa_a.txt";

// ===================================================================================

void ReverseString(std::string& str) {
    char temp;

    for (short i = 0; i < str.size() / 2; i++) {
        temp = str[i];
        str[i] = str[str.size() - i - 1];
        str[str.size() - i - 1] = temp;
    }
}

int main() {
    std::ifstream inputFile(INPUT_FILE_NAME);

    if(!inputFile.is_open()) { std::cout << "Error while opening the file"; }

    std::ofstream outputFilePass(OUTPUT_FILE_NAME), outputFileWords(OUTPUT2_FILE_NAME);

    std::string tempWord, shortestStr, longestStr;
    short minLength = 31, maxLength = 0;

    while (inputFile >> tempWord) {
        if (tempWord.size() < minLength) { minLength = tempWord.size(); shortestStr = tempWord; }
        if (tempWord.size() > maxLength) { maxLength = tempWord.size(); longestStr = tempWord; }

        ReverseString(tempWord);

        outputFilePass << tempWord << "\n";
        std::cout << tempWord << "\n";
    }

    outputFilePass.close();

    std::cout << "Minimal length: " << minLength << " in word \"" << shortestStr << "\"\n";
    outputFileWords << "Minimal length: " << minLength << " in word \"" << shortestStr << "\"\n";

    std::cout << "Max length: " << maxLength << " in word \"" << longestStr << "\"\n";
    outputFileWords << "Max length: " << maxLength << " in word \"" << longestStr << "\"\n";

    outputFileWords.close();
    return 0;
}
