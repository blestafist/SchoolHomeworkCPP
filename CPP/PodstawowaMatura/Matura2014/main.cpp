#include <iostream>
#include <fstream>
#include <utility>

// ================================ CONFIGURATION ===================================

const std::string INPUT_FILE_NAME = "PARY_LICZB.TXT"; // input file name here
const std::string OUTPUT_FILE_NAME = "ZADANIE5.TXT"; // output file name here

// =================================================================================


bool IsMultiplier(short num1, short num2) { // the numbers cannot be 0 (task), so i didnt checked if num 1 || num 2 == 0
	return (num1 > num2) ? (num1 % num2 == 0) : (num2 % num1 == 0);
}

bool GPD1(short num1, short num2) {
    while (num2) { // same as num2 != 0
        num1 %= num2;
		std::swap(num1, num2);
    }

	return num1 == 1;
}

unsigned char SumDigits(short num) {
	unsigned char result = 0;

	while (num > 0) {
		result += num % 10;
		num /= 10;
	}

	return result;
}


int main() {
	std::ifstream inputFile (INPUT_FILE_NAME);
	if (!inputFile.is_open()) { std::cerr << "Error while opening input file!"; return -1; }

	std::ofstream outputFile;

	short tempNum1, tempNum2; // limit is 30000, so using short (32768 max)
    short multiplierCounter = 0, gpd1Counter = 0, sumDigitsEqCounter = 0;

	// int tempNum;

	while (inputFile >> tempNum1 >> tempNum2) {
		if (IsMultiplier(tempNum1, tempNum2)) { multiplierCounter++; }
		if (GPD1(tempNum1, tempNum2)) { gpd1Counter++; }

		if (SumDigits(tempNum1) == SumDigits(tempNum2)) { sumDigitsEqCounter++; }

		// here place the conditions for nums / strs checking	
	}

	inputFile.close();
	
	outputFile.open(OUTPUT_FILE_NAME);
	if (!outputFile.is_open()) { std::cerr << "Error while opening output file!"; return -1; }

	std::cout << "a) Liczba par, w ktorych jedna liczba jest wielokrotnoscia drugiej: " << multiplierCounter << "\n\n";
    std::cout << "b) Liczba par wzglednie pierwszych (NWD = 1): " << gpd1Counter << "\n\n";
    std::cout << "c) Liczba par o tej samej sumie cyfr: " << sumDigitsEqCounter << "\n\n";

	outputFile << "a) Liczba par, w ktorych jedna liczba jest wielokrotnoscia drugiej: " << multiplierCounter << "\n\n";
    outputFile << "b) Liczba par wzglednie pierwszych (NWD = 1): " << gpd1Counter << "\n\n";
    outputFile << "c) Liczba par o tej samej sumie cyfr: " << sumDigitsEqCounter << "\n\n";
	
	outputFile.close();
	return 0;
}
