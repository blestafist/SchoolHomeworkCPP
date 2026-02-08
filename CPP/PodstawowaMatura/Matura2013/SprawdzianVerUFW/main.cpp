#include <iostream>
#include <fstream>


// ===================== CONFIGURATION =====================

const std::string INPUT_FILE = "napisy.txt";
const std::string OUTPUT_FILE = "zadanie4.txt";

// =========================================================

/* 

1. Count all words with size() % 2 == 0;
2. Count all words where num of '0' == num of '1'
3. Count words with:
    - All chars are '0'
    - All chars are '1'
4. Make an arr with .size()
5. Obfuscate the fucking code

*/

bool SameCharsQuantity(const std::string& str) {
    int numZeroes = 0, numOnes = 0;
    for (char c : str) {
        if (c == '0') { numZeroes++; }
        else { numOnes++; }
    }

    return numOnes == numZeroes;
}

bool ConsistsOnlyOneType(const std::string& str, char flag) {
    for (char c : str) {
        if (c != flag) { return false; }
    }

    return true;
}

int main() {
    std::ifstream inputFile (INPUT_FILE);

    if (!inputFile.is_open()) { std::cout << "Error while opening the file"; return -1; }

    std::ofstream outputFile;

    std::string tempWord;

    // define counters
    int evenCharsCounter = 0, sameCharsQuantityCounter = 0, wordsOnlyFromZeroes = 0, wordsOnlyFromOnes = 0;

    // define an array with "cups"
    int sizeArr[15] {};

    while (inputFile >> tempWord) {
        if (tempWord.size() % 2 == 0) { evenCharsCounter++; }
        if (SameCharsQuantity(tempWord)) { sameCharsQuantityCounter++; }
        else if (ConsistsOnlyOneType(tempWord, '0')) { wordsOnlyFromZeroes++; }
        else if (ConsistsOnlyOneType(tempWord, '1')) { wordsOnlyFromOnes++; }

        sizeArr[tempWord.size() - 2]++;
    }

    inputFile.close();

    outputFile.open(OUTPUT_FILE);

    std::cout << "1. Ilość napisów o parzystej długości: " << evenCharsCounter;
    outputFile << "1. Ilość napisów o parzystej długości: " << evenCharsCounter;

    std::cout << "\n\n2. Ilość napisów, zawierających tą samą liczbę zer i jedynek: " << sameCharsQuantityCounter;
    outputFile << "\n\n2. Ilość napisów, zawierających tą samą liczbę zer i jedynek: " << sameCharsQuantityCounter;

    std::cout << "\n\n3. Ilość napisów, zawierających same zera: " << wordsOnlyFromZeroes;
    std::cout << "\nIlość napisów, zawierających same jedynki: " << wordsOnlyFromOnes;
    outputFile << "\n\n3. Ilość napisów, zawierających same zera: " << wordsOnlyFromZeroes;
    outputFile << "\nIlość napisów, zawierających same jedynki: " << wordsOnlyFromOnes;

    std::cout << "\n\n4. Ilośc napisów o długości K: \n";
    outputFile << "\n\n4. Ilośc napisów o długości K: \n";

    for (int i = 0; i < 15; i++) {
        std::cout << i + 2 << ": " << sizeArr[i] << "\n";
        outputFile << i + 2 << ": " << sizeArr[i] << "\n";
    }


    outputFile.close();
    return 0;
}