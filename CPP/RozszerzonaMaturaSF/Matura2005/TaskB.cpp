#include <iostream>
#include <fstream>

// =========================== CONFIGURATION ===========================

const std::string INPUT_FILE_NAME = "dane5-3.txt";

// =====================================================================

int main() {
    std::ifstream inputFile (INPUT_FILE_NAME);
    if (!inputFile) { std::cerr << "Error while opening input file!"; return -1; }

    int localSum = 0,
    maxSum = 0,
    currInt;

    while (inputFile >> currInt) {
        localSum += currInt;
        if (localSum < 0) {
            localSum = 0;
        }

        if (localSum > maxSum) { maxSum = localSum; }
    }

    std::cout << maxSum;
}
