#include <iostream>
#include <fstream>
#include <cstdint>

// ================================ CONFIGURATION ===================================

const std::string INPUT_FILE_NAME = "dane.txt"; // input file name here
const std::string OUTPUT_FILE_NAME = "wyniki6.txt"; // output file name here

const int FILE_LENGTH = 1000; // lenth of input data array

// =================================================================================

bool IsMan(const std::string* pesel) {
	char overLast = (*pesel)[(*pesel).size() - 2] - 48;
	return overLast % 2 == 1;
}

bool IsBornInNovember(const std::string* pesel) {
	return ((*pesel)[2] == '1' && (*pesel)[3] == '1') || ((*pesel)[2] == '3' && (*pesel)[3] == '1');
}

bool IsCorrect(const std::string* pesel) {
	short result;

	result = (1 * (*pesel)[0]) + (3 * (*pesel)[1]) + (7 * (*pesel)[2]) + (9 * (*pesel)[3]) + (1 * (*pesel)[4]) + (3 * (*pesel)[5]) + (7 * (*pesel)[6]) + (9 * (*pesel)[7]) + (1 * (*pesel)[8]) + (3 * (*pesel)[9]) + (*pesel)[10];

	return result % 10 == 0;
}


int main() {
	std::ifstream inputFile(INPUT_FILE_NAME);
	std::ofstream outputFile;

	std::string tempWord; // string cause all operation on pesel will be better to make on strs

	std::cout << CharToByte('5');

	for (int i = 0; i < FILE_LENGTH; i++) {
		inputFile >> tempWord;

		// here place the conditions for nums / strs checking	
	}

	inputFile.close();
	
	outputFile.open(OUTPUT_FILE_NAME);

	// write answers
	
	outputFile.close();

	return 0;
}
