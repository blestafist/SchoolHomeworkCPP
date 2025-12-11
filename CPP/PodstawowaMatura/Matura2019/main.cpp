#include <iostream>
#include <fstream>

// ================================ CONFIGURATION ===================================

const std::string INPUT_FILE_NAME = "dane.txt"; // input file name here
const std::string OUTPUT_FILE_NAME = "wyniki6.txt"; // output file name here

const int FILE_LENGTH = 1000; // lenth of input data array

// =================================================================================

bool IsMan(const std::string* pesel) {
	char overLast = (*pesel)[(*pesel).size() - 2] - 48;
	return overLast % 2 == 1;
}

int main() {
	std::ifstream inputFile(INPUT_FILE_NAME);
	std::ofstream outputFile;

	std::string tempWord; // string cause all operation on pesel will be better to make on strs

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
