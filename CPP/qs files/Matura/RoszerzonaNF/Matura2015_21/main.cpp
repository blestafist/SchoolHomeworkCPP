#include <array>
#include <cstddef>
#include <fstream>
#include <iostream>


// ============================ CONFIGURATION ============================

const std::array<std::string, 3> INPUT_FILES { "liczby1.txt", "liczby2.txt", "liczby3.txt" };

// =======================================================================


bool IsDivisible (std::string_view binary, int divisor) {
    int remainder = 0;

    for (char c : binary) {
        int bit = c - '0';
        remainder = ((remainder << 1) + bit) % divisor;
    }
    return remainder == 0;
}


int main() { 
    std::ofstream outputFile("podzielność.txt");
    if (!outputFile) { std::cerr << "ERROR: Could not open outputFile" << std::endl; return 1; }

    for (size_t f = 0; f < INPUT_FILES.size(); ++f) {
        std::ifstream inputFile(INPUT_FILES[f]);
        if (!inputFile) { std::cerr << "ERROR: File " << INPUT_FILES[f] << " not found" << std::endl; return 1; }
        
        std::string binaryStr;

        int count2 = 0, count3 = 0, count5 = 0;
        while (inputFile >> binaryStr) {
            if (!binaryStr.empty()) {
                if (binaryStr.back() == '0') { count2++; } 
            }

            if (IsDivisible(binaryStr, 3)) { count3++; }

            if (IsDivisible(binaryStr, 5)) { count5++; }
        }

        std::cout << "dla pliku " << INPUT_FILES[f] << ":\nliczb podzilnych przez 2: " << count2
        << "\nliczb podzilnych przez 3: " << count3 << "\nliczb podzilnych przez 5: " << count5 << "\n\n";

        outputFile << count2 << '\n' << count3 << '\n' << count5 << '\n';
    }

    return 0;
}