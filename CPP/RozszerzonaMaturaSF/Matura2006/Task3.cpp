#include <iostream>
#include <fstream>

// =========================== CONFIGURATION ===========================

const std::string INPUT_FILE_NAME = "dane.txt";
const std::string OUTPUT_FILE_NAME = "wynik.txt";

// =====================================================================

bool IsPalidrome(const std::string& str) {
    for (size_t i = 0; i < str.size() / 2; i++) {
        if (str[i] != str[str.size() - 1 - i]) { return false; }
    }

    return true;
}

int main() {
    std::ifstream inputFile (INPUT_FILE_NAME);
    if (!inputFile) { std::cerr << "Error while opening input file!"; return -1;}

    std::ofstream outputFile (OUTPUT_FILE_NAME);
    if (!outputFile) { std::cerr << "Error while opening output file!"; return -1; }

    std::string tempWord;

    auto Print = [&] (auto&&... args) { (std::cout << ... << args) << "\n"; (outputFile << ... << args) << "\n"; };

    int counter = 0;

    while (inputFile >> tempWord) {
        if (IsPalidrome(tempWord)) { ++counter; }
    }

    Print("Ilość palidromnych liczb w pliku: ", counter);
    return 0;
}
