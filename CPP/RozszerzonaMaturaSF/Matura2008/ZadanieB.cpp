#include <fstream>
#include <iostream>
#include <string>
#include <vector>


// ================================== CONFIGURATION ==================================

const std::string INPUT_FILE_NAME = "slowa.txt";
const std::string OUTPUT_FILE_NAME = "hasla_b.txt";
const std::string OUTPUT2_FILE_NAme = "slowa_b.txt";

// ===================================================================================

bool IsPalindrome(const std::string& str) {
    for (char i = 0; i < str.size() / 2; i++) {
        if (str[i] != str[str.size() - 1 - i]) { return false; }
    }

    return true;
}

std::string ReturnW2(std::string str) { // transferring by value
    std::string anotherPart = "";

    do {
        if (IsPalindrome(str)) { // if is palidrome compose a new pass
            return anotherPart;
        }

        // if not move character to
        // ! ANOTHER  
        // var
        
        anotherPart += str[str.size() - 1];
        str.pop_back();

    } while (str.size() > 1);

    return anotherPart;
}

int main() {
    std::ifstream inputFile(INPUT_FILE_NAME);
    if(!inputFile.is_open()) { std::cout << "Error while opening the file"; }

    std::ofstream outputFilePass(OUTPUT_FILE_NAME), outputFileWords(OUTPUT2_FILE_NAme);
    std::string tempWord, wordModified, shortestStr, longestStr;
    short minLength, maxLength;
    int sumOfLength = 0;

    std::vector<std::string> contains12Chars {};

    inputFile >> tempWord;
    shortestStr = tempWord; longestStr = tempWord; minLength = tempWord.size(); maxLength = tempWord.size();

    while (inputFile >> tempWord) {
        wordModified = ReturnW2(tempWord) + tempWord;
        outputFilePass << wordModified << "\n";
        std::cout << wordModified << "\n";

        if (wordModified.size() == 12) { contains12Chars.push_back(wordModified); }

        if (wordModified.size() < minLength) { minLength = wordModified.size(); shortestStr = wordModified; }
        if (wordModified.size() > maxLength) { maxLength = wordModified.size(); longestStr = wordModified; }

        sumOfLength += wordModified.size();
    }

    outputFilePass.close();

    std::cout << "\n\nHasła o długości 12: \n";
    outputFileWords << "\n\nHasła o długości 12: \n";
    for (short i = 0; i < contains12Chars.size(); i++) { std::cout << contains12Chars[i] << "\n"; outputFileWords << contains12Chars[i] << "\n"; }
    
    std::cout << "\n\nNajdłuższe hasło: " << longestStr << "\n\nNajkrótsze hasło: " << shortestStr << "\n\nSuma długości wszystkich haseł: " << sumOfLength << "\n";
    outputFileWords << "\n\nNajdłuższe hasło: " << longestStr << "\n\nNajkrótsze hasło: " << shortestStr << "\n\nSuma długości wszystkich haseł: " << sumOfLength << "\n";

    return 0;
}
