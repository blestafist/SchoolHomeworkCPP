#include <iostream>
#include <fstream>

// =========================== CONFIGURATION ===========================

const std::string INPUT_FILE = "dane.txt";
const std::string OUTPUT_FILE = "wyniki6.txt";

// =====================================================================

bool SameDigitsDecimalCheck(const std::string& str) {
    int result = 0;
    for (char c : str) {
        result = result * 8 + (c - '0');
    }

    char lastNum = result % 10;
    result /= 10;

    while (result > 0) {
        if (result < 10 && result == lastNum) { return true; }
    }

    return false;
}

int main() {
    std::ifstream inputFile (INPUT_FILE);
    std::ofstream outputFile (OUTPUT_FILE);

    std::string eightNum;
    short eightSameDigitsCounter = 0, decimalSameDigitsCounter = 0, increasingCounter = 0;

    while (inputFile >> eightNum) {
        if (eightNum[0] == eightNum[eightNum.size() - 1]) { eightSameDigitsCounter++; }
        if (SameDigitsDecimalCheck(eightNum)) { decimalSameDigitsCounter++; }
    }
}