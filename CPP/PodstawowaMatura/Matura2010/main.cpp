#include <iostream>
#include <fstream>

// =========================== CONFIGURATION ===========================

const std::string INPUT_FILE = "dane.txt";
const std::string OUTPUT_FILE = "zadanie4.txt";

// =====================================================================


bool IsPalidrome(const std::string& str) {
    for (char i = 0; i < str.size() / 2; i++) {
        if (str[i] != str[str.size() - 1 - i]) { return false; }
    }

    return true;
}

int main() {
    std::ifstream inputFile (INPUT_FILE);
    std::ofstream outputFile (OUTPUT_FILE);

    std::string tempWord;

    while (inputFile >> tempWord) {
        if (IsPalidrome(tempWord)) { outputFile << tempWord << "\n"; std::cout << tempWord << "\n"; }
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
