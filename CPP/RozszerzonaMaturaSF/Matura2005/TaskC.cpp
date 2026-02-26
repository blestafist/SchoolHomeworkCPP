#include <iostream>
#include <fstream>
#include <unordered_map>

// =========================== CONFIGURATION ===========================

const std::string INPUT_FILE_NAME = "dane5-1.txt";

// =====================================================================

int main() {
    std::ifstream inputFile (INPUT_FILE_NAME);
    if (!inputFile) { std::cerr << "Error while opening input file!"; return -1; }

    std::unordered_map<int, int> map; // element : occ

    int currInt,
    maxOccValue = 0,
    maxOccKey;

    while (inputFile >> currInt) {
        map[currInt]++;
    }

    for (const auto& [key, value] : map) {
        if (maxOccValue < value) { maxOccValue = value; maxOccKey = key; }
    }

    std::cout << maxOccKey;
}
