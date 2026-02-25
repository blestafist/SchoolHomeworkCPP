#include <iostream>
#include <fstream>
#include <string>
#include <sys/types.h>
#include <unordered_map>

// =========================== CONFIGURATION ===========================

const std::string INPUT_FILE_NAME = "galerie.txt";
const std::string OUTPUT_FILE_NAME = "wynik4_1.txt";

// =====================================================================

int main() {
    std::ifstream inputFile (INPUT_FILE_NAME);
    if (!inputFile) { std::cerr << "Error while opening input file!"; return -1; }

    std::ofstream outputFile (OUTPUT_FILE_NAME);
    if (!outputFile) { std::cerr << "Error while opening output file!"; return -1; }

    std::string tempWord;
    std::unordered_map<std::string, int> map; // key → country code | value → count of occ

    while (inputFile >> tempWord) {
        inputFile.ignore(10000, '\n');
        map[tempWord]++;
    }

    for (const auto& [country, val] : map) {
        std::cout << country << ' ' << val << "\n";
        outputFile << country << ' ' << val << "\n";
    }

    return 0;
}
