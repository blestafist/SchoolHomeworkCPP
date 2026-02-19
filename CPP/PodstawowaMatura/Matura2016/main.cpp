#include <cstddef>
#include <iostream>
#include <fstream>
#include <vector>
#include <limits.h>

// ================================ CONFIGURATION ===================================

std::string INPUT_FILE_NAME = "dane_6.txt"; // input file name here
std::string OUTPUT_FILE_NAME = "wyniki_6.txt"; // output file name here

// =================================================================================

// additional funcs
bool IsPrime(short num) {
    if (num == 2 || num == 3) { return true; }
    if (num % 2 == 0 || num % 3 == 0 || num < 2) { return false; }

    for (short i = 5; i * i < num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) { return false; }
    }

    return true;
}

// entry point
int main() {
	std::ifstream inputFile(INPUT_FILE_NAME);
    if (!inputFile) { std::cerr << "Error while opening input file!"; return -1; }

	std::ofstream outputFile (OUTPUT_FILE_NAME);
    if (!outputFile) { std::cerr << "Error while opening output file!"; return -1; }

    std::vector<short> primeNums;

    short highest = SHRT_MIN, 
    lowest = SHRT_MAX, 
    primeNumsCount = 0;

    short tempWord; // string / int (change on need)

    auto AreNeightbors = [] (short a, short b) -> bool { return a - b == 2 || b - a == 2; };
    auto Print = [&] (auto&&... args) -> void { (std::cout << ... << args) << "\n"; (outputFile << ... << args) << "\n"; };
    

	while (inputFile >> tempWord) {
        if (IsPrime(tempWord)) { 
            primeNums.push_back(tempWord); 
            primeNumsCount++; 

            if (tempWord > highest) { highest = tempWord; }
            if (tempWord < lowest) {lowest = tempWord; }
        }
	}

    Print("Zadanie 6.1: \nIlosc liczb pierwszych: ", primeNumsCount, "\n");
    Print("Zadanie 6.2: \nMinimalna liczba pierwsza: ", lowest, "\nMaksymalna liczba pierwsza: ", highest, "\n");
    Print("Zadanie 6.3. Liczby blużniące: ");
	
    for (size_t i = 0; i < primeNums.size() - 1; i++) {
        if(AreNeightbors(primeNums[i], primeNums[i + 1])) {
            Print(primeNums[i], " i ", primeNums[i + 1]);
        }
    }

	return 0;
}
