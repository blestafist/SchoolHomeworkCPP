#include <iostream>
#include <fstream>

// ================================ CONFIGURATION ===================================

const std::string INPUT_FILE = ""; // input file name here
const std::string OUTPUT_FILE = ""; // output file name here

// =================================================================================

int main() {
	std::ifstream inputFile (INPUT_FILE);
	if (!inputFile) { std::cerr << "Error while opening input file!"; return -1; }

	std::ofstream outputFile;

	std::string tempWord; // string / int (change on need)	
	// int tempNum;

	while (inputFile >> tempWord) {

		// here place the conditions for nums / strs checking	
	}

	inputFile.close();
	
	outputFile.open(OUTPUT_FILE);
	if (!outputFile) { std::cerr << "Error while opening output file!"; return -1; }

	// write answers
	
	outputFile.close();

	return 0;
}
