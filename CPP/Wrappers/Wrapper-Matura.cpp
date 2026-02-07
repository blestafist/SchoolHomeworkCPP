#include <iostream>
#include <fstream>

// ================================ CONFIGURATION ===================================

const std::string INPUT_FILE_NAME = ""; // input file name here
const std::string OUTPUT_FILE_NAME = ""; // output file name here

// =================================================================================

// minimal wrapper for program (remove comment)

int main() {
	std::ifstream inputFile (INPUT_FILE_NAME);
	std::ofstream outputFile;

	std::string tempWord; // string / int (change on need)
	// int tempNum;

	while (inputFile >> tempWord) {
		inputFile >> tempWord;

		// here place the conditions for nums / strs checking	
	}

	inputFile.close();
	
	outputFile.open(OUTPUT_FILE_NAME);

	// write answers
	
	outputFile.close();

	return 0;
}
