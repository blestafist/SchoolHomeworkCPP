#include <iostream>
#include <fstream>

// ================================ CONFIGURATION ===================================

std::string INPUT_FILE_NAME = ""; // input file name here
std::string OUTPUT_FILE_NAME = ""; // output file name here

int FILE_LENGTH = 1000; // lenth of input data array

// =================================================================================

// minimal wrapper for program (remove comment)

int main() {
	std::ifstream inputFile(INPUT_FILE_NAME);
	std::ofstream outputFile;

	std::string tempWord; // string / int (change on need)

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
