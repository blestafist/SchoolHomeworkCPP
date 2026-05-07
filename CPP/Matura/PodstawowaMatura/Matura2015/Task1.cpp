#include <iostream>
#include <fstream>

// ======================== CONFIGURATION ========================

const std::string INPUT_FILE_NAME = "slowa.txt";
const std::string OUTPUT_FILE_NAME = "wynik5.txt";

// ===============================================================

int main() {
    std::ifstream inputFile (INPUT_FILE_NAME);
    if (!inputFile) { std::cerr << "Error while opening input files!"; return -1; }

    std::ofstream outputFile (OUTPUT_FILE_NAME);
    if (!outputFile) { std::cerr << "Error while opening output file!"; return -1; }

    std::string tempWord;

    int cupArr[12] {}; // cup array for counting natural nums 

    while (inputFile >> tempWord) {
        cupArr[tempWord.size() - 1]++;
    }

    for (char i = 0; i < 12; i++) {
        std::cout << (int)i + 1 << " → " << cupArr[i] << "\n";
        outputFile << (int)i + 1 << " → " << cupArr[i] << "\n";
    }

    return 0;
}