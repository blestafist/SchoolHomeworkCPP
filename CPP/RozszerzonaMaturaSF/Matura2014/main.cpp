#include <iostream>
#include <fstream>
#include <unordered_map>

// =========================== CONFIGURATION ===========================

const std::string INPUT_FILE_NAME = "NAPIS.TXT";
const std::string OUTPUT_FILE_NAME = "ZADANIE5.TXT";

// =====================================================================

bool IsPrime(int num) {
    if (num == 2 || num == 3) { return true; }
    if (num % 2 == 0 || num % 3 == 0 || num < 2) { return false; }

    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) { return false; }
    }

    return true;
}

bool SumASCIIPrime(const std::string& str) {
    int result = 0;

    for (char c : str) {
        result += c;
    }

    return IsPrime(result);
}

bool IncreasingString(const std::string& str) {
    for (int i = 0; i < str.size() - 1; i++) {
        if (str[i] >= str[i + 1]) { return false; }
    }

    return true;
}

int main() {
    std::ifstream inputFile (INPUT_FILE_NAME);
    std::ofstream outputFile (OUTPUT_FILE_NAME);
    if (!inputFile) { std::cerr << "Error while opening input file!"; return -1; }

    std::string tempWord, increasingStrings;
    size_t primeStringsCount = 0;

    std::unordered_map<std::string, int> wordsOcc; // word : count
    auto Print = [&] (auto&&... args) { (std::cout << ... << args) << "\n"; (outputFile << ... << args) << "\n"; };

    while (inputFile >> tempWord) {
        if (SumASCIIPrime(tempWord)) { primeStringsCount++; }
        if (IncreasingString(tempWord)) { increasingStrings += tempWord + "\n"; }

        wordsOcc[tempWord]++;
    }

    Print("Ilość napisów pierwszych: ", primeStringsCount);
    Print("\nNapisy rosnące: \n", increasingStrings);
    Print("\nNapisy, występujące więcej niż 1 raz: ");

    for (const auto& [key, value] : wordsOcc) {
        if (value > 1) { Print(key); }
    }

    return 0;
}