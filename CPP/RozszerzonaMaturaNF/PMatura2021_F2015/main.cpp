#include <iostream>
#include <fstream>

// =========================== CONFIGURATION ===========================

const std::string INPUT_FILE_NAMES[3] = { "liczby1.txt", "liczby2.txt", "liczby3.txt" };
const std::string OUTPUT_FILE_NAME = "wyniki.txt";

// =====================================================================

bool IsDividable(const std::string& bin, int divisor) {
    int reminder = 0;

    for (char c : bin) {
        reminder = ((reminder << 1) + (c - '0')) % divisor;
    }

    return reminder == 0;
}


int main() {
    std::ofstream outputFile (OUTPUT_FILE_NAME);
    if (!outputFile) { std::cerr << "Error while opening output file!"; return -1; }

    std::string tempBinary;
    auto Print = [&] (auto&&... args) { (std::cout << ... << args) << "\n"; (outputFile << ... << args) << "\n"; };

    for (const std::string& fileName : INPUT_FILE_NAMES) {
        std::ifstream inputFile (fileName);
        if (!inputFile) { std::cerr << "Error while opening input file!"; return -1; }

        int dividable2Counter = 0,
        dividable3Counter = 0,
        dividable5Counter = 0;

        while (inputFile >> tempBinary) {
            if (IsDividable(tempBinary, 2)) { ++dividable2Counter; }
            if (IsDividable(tempBinary, 3)) { ++dividable3Counter; }
            if (IsDividable(tempBinary, 5)) { ++dividable5Counter; }
        }

        Print("Dla pliku ", fileName, "liczby podzielne przez 2: ", dividable2Counter);
        Print("Dla pliku ", fileName, "liczby podzielne przez 3: ", dividable3Counter);
        Print("Dla pliku ", fileName, "liczby podzielne przez 5: ", dividable5Counter, '\n');
    }

    return 0;
}
