#include <algorithm>
#include <clocale>
#include <iostream>
#include <fstream>

// =========================== CONFIGURATION ===========================

const std::string INPUT_FILE = "liczby.txt";
const std::string OUTPUT_FILE = "zadanie6.txt";

// =====================================================================


int ConvertToDecimal(const std::string& bin) {
    int result = 0;
    
    for (char c : bin) {
        result = (result << 1) + (c - '0');
    }

    return result;
}

std::string ConvertToBinary(int decimal) {
    std::string result = "";
    while (decimal > 0) {
        result += (decimal % 2) + '0';
        decimal /= 2;
    }

    std::reverse(result.begin(), result.end());
    return result;
}

int main() {
    setlocale(LC_ALL, "pl");

    std::ifstream inputFile(INPUT_FILE);
    std::ofstream outputFile(OUTPUT_FILE);

    std::string tempWord;
    int tempDecimal, maxDecimal = -1, sumOf9 = 0;
    short countEven = 0, count9 = 0;

    while (inputFile >> tempWord) {
        if (tempWord[tempWord.size() - 1] == '0') { countEven++; }

        tempDecimal = ConvertToDecimal(tempWord);
        if (tempDecimal > maxDecimal) { maxDecimal = tempDecimal; }

        if (tempWord.size() == 9) { sumOf9 += tempDecimal; count9++; }
    }

    std::cout << "Ilość parzystych liczb: " << countEven;
    outputFile << "Ilość parzystych liczb: " << countEven;

    std::cout << "\n\n\nNajwiększa liczba: " << maxDecimal << ", dwójkowy: " << ConvertToBinary(maxDecimal);
    outputFile << "\n\n\nNajwiększa liczba: " << maxDecimal << ", dwójkowy: " << ConvertToBinary(maxDecimal);

    std::cout << "\n\n\nIlość liczb z 9 cyframi: " << count9 << "\nIch suma: " << ConvertToBinary(sumOf9) << "\n";
    outputFile << "\n\n\nIlość liczb z 9 cyframi: " << count9 << "\nIch suma: " << ConvertToBinary(sumOf9) << "\n";

    return 0;
}