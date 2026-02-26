#include <iostream>
#include <fstream>

// =========================== CONFIGURATION ===========================

const std::string INPUT_FILE_NAME = "dane.txt";
const std::string OUTPUT_FILE_NAME = "wynik.txt";

const char EVEN_CHARS[3] = { 'A', 'C', 'E' };

// =====================================================================

int main() {
    std::ifstream inputFile (INPUT_FILE_NAME);
    if (!inputFile) { std::cerr << "Error while opening input file!"; return -1;}

    std::ofstream outputFile (OUTPUT_FILE_NAME);
    if (!outputFile) { std::cerr << "Error while opening output file!"; return -1; }

    std::string tempWord;

    auto Print = [&] (auto&&... args) { (std::cout << ... << args) << "\n"; (outputFile << ... << args) << "\n"; };

    int counter = 0;

    while (inputFile >> tempWord) {
        for (char c : EVEN_CHARS) {
            if (tempWord.back() == c) { ++counter; }
        }
    }

    Print("Ilość parzystych liczb w pliku: ", counter);
    return 0;
}
