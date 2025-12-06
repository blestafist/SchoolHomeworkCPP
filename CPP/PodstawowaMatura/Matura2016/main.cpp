#include <iostream>
#include <fstream>
#include <vector>
#include <limits.h>

// ================================ CONFIGURATION ===================================

std::string INPUT_FILE_NAME = "dane_6.txt"; // input file name here
std::string OUTPUT_FILE_NAME = "wyniki_6.txt"; // output file name here

int FILE_LENGTH = 2000; // lenth of input data array

// =================================================================================

// additional funcs
bool IsPrime(short num) {
    if (num < 0) { return false; }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) { return false; }
    }
    return true;
}

bool AreNeightbors(short x, short y) {
    if (x - y == 2 || y - x == 2) { return true; }
    return false;
}

// entry point
int main() {
	std::ifstream inputFile(INPUT_FILE_NAME);
	std::ofstream outputFile;

    std::vector<short> primeNums;
    int primeNumsCount = 0;
    short highest = -32768, lowest = 32767;

	short tempWord; // string / int (change on need)

	for (int i = 0; i < FILE_LENGTH; i++) {
		inputFile >> tempWord;
        if (IsPrime(tempWord)) { 
            primeNums.push_back(tempWord); 
            primeNumsCount++; 

            if (tempWord > highest) { highest = tempWord; }
            if (tempWord < lowest) {lowest = tempWord; }
        }
	}

	inputFile.close();
	
	outputFile.open(OUTPUT_FILE_NAME);

    std::cout << "Zadanie 6.1: \nIlosc liczb pierwszych: " << primeNumsCount << "\n\n"; 
    outputFile << "Zadanie 6.1: \nIlosc liczb pierwszych: " << primeNumsCount << "\n\n"; 

    std::cout << "Zadanie 6.2: \nMinimalna liczba pierwsza: " << lowest << "\nMaksymalna liczba pierwsza: " << highest << "\n\n"; 
    outputFile << "Zadanie 6.2: \nMinimalna liczba pierwsza: " << lowest << "\nMaksymalna liczba pierwsza: " << highest << "\n\n"; 

    std::cout << "Zadanie 6.3. Liczby blużniące: \n"; 
    outputFile << "Zadanie 6.3. Liczby blużniące: \n"; 
	
    for (int i = 0; i < primeNums.size() - 1; i++) {
        if(AreNeightbors(primeNums[i], primeNums[i + 1])) {
            std::cout << primeNums[i] << " i " << primeNums[i + 1] << std::endl;
            outputFile << primeNums[i] << " i " << primeNums[i + 1] << std::endl;
        }
    }

	outputFile.close();

	return 0;
}
