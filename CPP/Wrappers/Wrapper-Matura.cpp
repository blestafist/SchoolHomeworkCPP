#include <iostream>
#include <fstream>

// ================================ CONFIGURATION ===================================

std::string INPUT_FILE_NAME = ""; // input file name here
std::string OUTPUT_FILE_NAME = ""; // output file name here

int FILE_LENGTH = 1000; // lenth of input data array

// =================================================================================

// minimal wrapper for program (remove comment)

int main() {
	std::fstream inputFile, outputFile;
	std::string tempWord;

	inputFile.open(INPUT_FILE_NAME, std::ios::in);


	for (int i = 0; i < FILE_LENGTH; i++) {
		inputFile >> tempWord;

		// here place the conditions for nums / strs checking	
	}

	inputFile.close();
	
	outputFile.open(OUTPUT_FILE_NAME, std::ios::out);

	// write answers
	
	outputFile.close();

	return 0;
}
