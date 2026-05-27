#include <iostream>
#include <fstream>
#include <string>

// ================================== CONFIGURATION ==================================

const std::string INPUT_FILE_NAME = "pary_przyklad.txt";
const std::string OUTPUT_FILE_NAME = "wyniki3.txt";

// ===================================================================================

int main() {
	std::ifstream inputFile (INPUT_FILE_NAME);
	if (!inputFile) { std::cerr << "Error while opening input file!"; return 1; }

	std::ofstream outputFile (OUTPUT_FILE_NAME);

	std::string word1, word2;

	while (inputFile >> word1 >> word2) {

	}

	return 0;
}
