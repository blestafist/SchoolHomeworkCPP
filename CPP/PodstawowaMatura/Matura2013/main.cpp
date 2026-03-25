#include <iostream>
#include <fstream>


// ===================== CONFIGURATION =====================

const std::string INPUT_FILE_NAME = "napisy.txt";
const std::string OUTPUT_FILE_NAME = "zadanie4.txt";

// =========================================================


bool SameCharsQuantity(const std::string& str) {
    int counter = 0;
    for (char c : str) {
        c == '0' ? counter++ : counter--;
    }

    return counter == 0;
}


bool ConsistsOnlyOneType(const std::string& str, char flag) {
    for (char c : str) {
        if (c != flag) { return false; }
    }

    return true;
}


int main() {
    std::ifstream inputFile (INPUT_FILE_NAME);
    if (!inputFile) { std::cerr << "Error while opening input file"; return -1; }

    std::ofstream outputFile (OUTPUT_FILE_NAME);
    if (!outputFile) { std::cerr << "Error while opening output file!"; return -1; }
    std::string tempWord;

    int evenCharsCounter = 0,
        sameCharsQuantityCounter = 0,
        wordsOnlyFromZeroes = 0,
        wordsOnlyFromOnes = 0;

    int sizeArr[15] {};

    auto Print = [&](auto&&... args) {
        (std::cout << ... << args) << "\n";
        (outputFile << ... << args) << "\n";
    };

    while (inputFile >> tempWord) {
        if (tempWord.size() % 2 == 0) { evenCharsCounter++; }

        if      (SameCharsQuantity(tempWord)) { sameCharsQuantityCounter++; }
        else if (ConsistsOnlyOneType(tempWord, '0')) { wordsOnlyFromZeroes++; }
        else if (ConsistsOnlyOneType(tempWord, '1')) { wordsOnlyFromOnes++; }

        if (tempWord.size() >= 2 && tempWord.size() <= 16) {
            sizeArr[tempWord.size() - 2]++;
        }
    }

    Print("1. Ilość napisów o parzystej długości: ", evenCharsCounter);
    Print("\n2. Ilość napisów, zawierających tą samą liczbę zer i jedynek: ", sameCharsQuantityCounter);
    Print("\n3. Ilość napisów, zawierających same zera: ", wordsOnlyFromZeroes);
    Print("Ilość napisów, zawierających same jedynki: ", wordsOnlyFromOnes);
    Print("\n4. Ilość napisów o długości K: ");

    for (int i = 0; i < 15; i++) {
        Print(i + 2, ": ", sizeArr[i]);
    }

    return 0;
}