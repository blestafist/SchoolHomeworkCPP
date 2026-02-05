#include <iostream>
#include <fstream>
#include <limits.h>

// =========================== CONFIGURATION ===========================

const std::string INPUT_FILE = "dane.txt";
const std::string OUTPUT_FILE = "wyniki6.txt";

// =====================================================================

bool SameDigitsDecimalCheck(const std::string& str, int result) {
    char lastNum = result % 10;
    result /= 10;

    while (result > 0) {
        if (result < 10 && result == lastNum) { return true; }
        result /= 10;
    }

    return false;
}

int ConvertToDecimal(const std::string& str) {
    int result = 0;

    for (char c : str) {
        result = result * 8 + (c - '0');
    }

    return result;
}

bool IncreasingOrder(const std::string& str) {
    for (char i = 0; i < str.size() - 1; i++) {
        if (str[i] > str[i + 1]) { return false; }
    }
    
    return true;
}

int main() {
    std::ifstream inputFile (INPUT_FILE);
    std::ofstream outputFile (OUTPUT_FILE);

    std::string eightNum, max, min;
    int decimalNum, maxDecimal = INT_MIN, minDecimal = INT_MAX; 

    short eightSameDigitsCounter = 0, decimalSameDigitsCounter = 0, increasingCounter = 0;


    while (inputFile >> eightNum) {
        decimalNum = ConvertToDecimal(eightNum);


        if (eightNum[0] == eightNum[eightNum.size() - 1]) { eightSameDigitsCounter++; }

        if (SameDigitsDecimalCheck(eightNum, decimalNum)) { decimalSameDigitsCounter++; }

        if (IncreasingOrder(eightNum)) { 
            increasingCounter++; 
            if (decimalNum < minDecimal) { minDecimal = decimalNum; min = eightNum; }
            if (decimalNum > maxDecimal) { maxDecimal = decimalNum; max = eightNum; }
        }
    }

    inputFile.close();


    std::cout << "A. " << eightSameDigitsCounter;
    outputFile << "A. " << eightSameDigitsCounter;

    std::cout << "\n\nB. " << decimalSameDigitsCounter;
    outputFile << "\n\nB. " << decimalSameDigitsCounter;

    std::cout << "\n\nC. " << increasingCounter << "\nNajmniejsza: " << min << "\nNajwiększa: " << max << "\n\n";
    outputFile << "\n\nC. " << increasingCounter << "\nNajmniejsza: " << min << "\nNajwiększa: " << max << "\n\n";

    return 0;
}