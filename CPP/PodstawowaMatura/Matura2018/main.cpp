#include <iostream>
#include <fstream>
#include <vector>
#include <stdint.h>

// ================================ CONFIGURATION ===================================

const std::string INPUT_FILE_NAME = "liczby.txt"; // input file name here
const std::string OUTPUT_FILE_NAME = "wyniki5.txt"; // output file name here

const int FILE_LENGTH = 1000; // lenth of input data array

// =================================================================================

// addiitonal funcs

bool ReversedEqualsOrginal(short num) {
    short reversed = 0, original = num;
    while (num > 0) {
        reversed *= 10;
        reversed += num % 10;
        num /= 10;
    }

    return reversed == original;
} 

uint8_t SumDigitals(short num) {
    uint8_t result = 0;

    while (num > 0) {
        result += num % 10;
        num /= 10;
    }

    return result;
}

// entry point
int main() {
	std::ifstream inputFile(INPUT_FILE_NAME);
	std::ofstream outputFile;

    std::vector<unsigned short> palindromeNumbers;
    std::vector<unsigned short> sumGreaterThan30;

	unsigned short tempWord, highestEvenNum = 0; // short because limited 30000, unsigned just for safety
    unsigned short sumOfAllDigitals = 0; // max sum of digitals in a number limited by 30000 is 38, so 38 * 1000 = 38000, 
    // unsigned short contains that (up to 65000)

	for (int i = 0; i < FILE_LENGTH; i++) {
		inputFile >> tempWord;

        if (highestEvenNum < tempWord) { // check if greater (most optimised way)
            if (tempWord % 2 == 0) { // check if even
                highestEvenNum = tempWord;
            }
        }

        if (ReversedEqualsOrginal(tempWord)) { palindromeNumbers.push_back(tempWord); }

        if (SumDigitals(tempWord) > 30) { sumGreaterThan30.push_back(tempWord); }
        sumOfAllDigitals += SumDigitals(tempWord);
	}

	inputFile.close();
	
	outputFile.open(OUTPUT_FILE_NAME);

	std::cout << "Zadanie 5.1. Największa liczba parzysta: " << highestEvenNum << "\n\n";
    outputFile << "Zadanie 5.1. Największa liczba parzysta: " << highestEvenNum << "\n\n";

    std::cout << "Zadanie 5.2. Wszystkie palindromiczne liczby: " << "\n";
    outputFile << "Zadanie 5.2. Wszystkie palindromiczne liczby: " << "\n";
    for (int i = 0; i < palindromeNumbers.size(); i++) {
        std::cout << palindromeNumbers[i] << "\n";
        outputFile << palindromeNumbers[i] << "\n";
    }

    std::cout << "\nZadanie 5.3. Liczby, których suma cyfr jest większa od 30: \n";
    outputFile << "\nZadanie 5.3. Liczby, których suma cyfr jest większa od 30: \n";
    for (int i = 0; i < sumGreaterThan30.size(); i++) {
        std::cout << sumGreaterThan30[i] << "\n";
        outputFile << sumGreaterThan30[i] << "\n";
    }

    std::cout << "\nSuma wszystkich cyfr w pliku: " << sumOfAllDigitals;
    outputFile << "\nSuma wszystkich cyfr w pliku: " << sumOfAllDigitals;
	
	outputFile.close();

	return 0;
}
