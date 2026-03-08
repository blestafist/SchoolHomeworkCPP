#include <iostream>
#include <fstream>
#include <unordered_map>

// =========================== CONFIGURATION ===========================

const std::string INPUT_FILE_NAMES[] = { "dane5-1.txt", "dane5-2.txt", "dane5-3.txt" };

// =====================================================================

int main() {
    for (const std::string& fileName : INPUT_FILE_NAMES) {
        std::ifstream inputFile (fileName);
        if (!inputFile) { std::cerr << "Error while opening input file!"; return -1; }

        std::unordered_map<int, int> map; // element : occ

        int currInt,
        maxOccValue = 0,
        maxOccKey = 0;

        while (inputFile >> currInt) {
            map[currInt]++;
        }

        for (const auto& [key, value] : map) {
            if (maxOccValue < value) { maxOccValue = value; maxOccKey = key; }
        }

        std::cout << "Dla pliku " << fileName << " → " << maxOccKey << "\n";
    }
}
