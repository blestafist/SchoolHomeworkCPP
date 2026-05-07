#include <iostream>
#include <fstream>

// ================================ CONFIGURATION ===================================

const std::string INPUT_FILE_NAME = "PARY_LICZB.TXT"; // input file name here
const std::string OUTPUT_FILE_NAME = "ZADANIE5.TXT"; // output file name here

// =================================================================================


bool IsMultiplier(int a, int b) {
    // both positive by task statement
    return (a > b) ? (a % b == 0) : (b % a == 0);
}

int GCD(int a, int b) {
    return b ? GCD(b, a % b) : a;
}

int SumDigits(int n) {
    int s = 0;
    while (n > 0) { s += n % 10; n /= 10; }
    return s;
}

int main() {
    std::ifstream inputFile(INPUT_FILE_NAME);
    if (!inputFile.is_open()) { std::cerr << "Error while opening input file!"; return -1; }

    int a, b;
    int multiplierCounter = 0, gpd1Counter = 0, sumDigitsEqCounter = 0;

    while (inputFile >> a >> b) {
        if (IsMultiplier(a, b)) ++multiplierCounter;
        if (GCD(a, b) == 1) ++gpd1Counter;
        if (SumDigits(a) == SumDigits(b)) ++sumDigitsEqCounter;
    }
    inputFile.close();

    std::ofstream outputFile(OUTPUT_FILE_NAME);
    if (!outputFile.is_open()) { std::cerr << "Error while opening output file!"; return -1; }

    // lambda printing to both cout and file
    auto Print = [&](auto&&... args) {
        (std::cout << ... << args) << "\n";
        (outputFile << ... << args) << "\n";
    };

    Print("a) ", "Ile jest wierszy, w których jedna z liczb jest wielokrotnością drugiej? ", multiplierCounter);
    Print("\nb) ", "Ile jest wierszy zawierających pary względnie pierwsze (NWD = 1)? ", gpd1Counter);
    Print("\nc) ", "Ile jest wierszy, dla których suma cyfr pierwszej liczby jest równa sumie cyfr drugiej liczby? ", sumDigitsEqCounter);

    outputFile.close();
    return 0;
}
