#include <iostream>
#include <fstream>
#include <limits.h>

// =========================== CONFIGURATION ===========================

const std::string INPUT_FILE_NAMES[] = { "dane5-1.txt", "dane5-2.txt", "dane5-3.txt" };

// =====================================================================

int main() {
    for (const std::string& fileName : INPUT_FILE_NAMES) {
        std::ifstream inputFile (fileName);
        if (!inputFile) { std::cerr << "Error while opening input file!"; return -1; }

        int tempInt; inputFile >> tempInt;

        int localSum = tempInt,
        maxSum = tempInt,
        currInt;

        while (inputFile >> currInt) {
            localSum = std::max(localSum + currInt, currInt);
            if (localSum > maxSum) { maxSum = localSum; }
        }

        std::cout << "Dla pliku " << fileName << " → " << maxSum << "\n";
    }
}
