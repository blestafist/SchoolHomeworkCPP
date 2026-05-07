#include <iostream>
#include <fstream>

// ================================ CONFIGURATION ===================================

std::string INPUT_FILE_NAME = "cyfry.txt"; // input file name here
std::string OUTPUT_FILE_NAME = "zadanie4.txt"; // output file name here

int FILE_LENGTH = 1000; // lenth of input data array

// =================================================================================

// minimal wrapper for program (remove comment)

bool DigitsIncreasingOrder(int num) {
    int lastNum = 10;

    while (num > 0) {
        if (lastNum <= num % 10) { return false; }
        lastNum = num % 10;
        num /= 10;
    }

    return true;
}


int main() {
	std::fstream inputFile, outputFile;
	int tempWord;

	inputFile.open(INPUT_FILE_NAME, std::ios::in);
	outputFile.open(OUTPUT_FILE_NAME, std::ios::app);

	std::cout << "Zadanie C. Liczby w increasing order: " << std::endl;
	outputFile << "Zadanie C. Liczby w increasing order: " << std::endl;

	for (int i = 0; i < FILE_LENGTH; i++) {
		inputFile >> tempWord;

		// here place the conditions for nums / strs checking	
		
		if (DigitsIncreasingOrder(tempWord)) {
			std::cout << tempWord << std::endl;
			outputFile << tempWord << std::endl;
		}
	}

	inputFile.close();
	outputFile.close();

	return 0;
}
