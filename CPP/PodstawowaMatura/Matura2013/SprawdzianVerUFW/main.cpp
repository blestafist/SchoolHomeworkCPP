#include <iostream>
#include <fstream>


// ===================== CONFIGURATION =====================

const std::string INPUT_FILE = "dzialki.txt";
const std::string OUTPUT_FILE = "wynik4.txt";

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
    std::ofstream outputFile;

    std::string tempWord;

    // define counters
    int evenCharsCounter = 0, sameCharsQuantityCounter = 0, wordsOnlyFromZeroes = 0, wordsOnlyFromOnes = 0;

    // define an array with "cups"
    int sizeArr[14] {};

    while (inputFile >> tempWord) {
        if (tempWord.size() % 2 == 0) { evenCharsCounter++; }
        if (SameCharsQuantity(tempWord)) { sameCharsQuantityCounter++; }
        else if (ConsistsOnlyOneType(tempWord, '0')) { wordsOnlyFromZeroes++; }
        else if (ConsistsOnlyOneType(tempWord, '1')) { wordsOnlyFromOnes++; }

        
    }

    inputFile.close();

    outputFile.open(OUTPUT_FILE);


    outputFile.close();
    return 0;
}