#include <iostream>
#include <fstream>
#include <string>

// ================================== CONFIGURATION ==================================

const std::string INPUT_FILE_NAME = "pary_przyklad.txt";
const std::string OUTPUT_FILE_NAME = "wyniki3.txt";

// ===================================================================================

int SumASCII (const std::string& str) {
	int result = 0;
	for (char c : str) {
		result += c;
	}

	return result;
}

int ABS (int num) {
	if (num < 0) {
		num *= -1;
	}

	return num;
}

int main() {
	std::ifstream inputFile (INPUT_FILE_NAME);
	if (!inputFile) { std::cerr << "Error while opening input file!"; return 1; }

	std::ofstream outputFile (OUTPUT_FILE_NAME);

	std::string word1, word2, maxWord;
	int maxSum = -1;

	while (inputFile >> word1 >> word2) {
		int curr = ABS(SumASCII(word1) - SumASCII(word2));
		if (maxSum == -1 || curr > maxSum) {
			maxSum = curr;
			maxWord = word1 + ' ' + word2;
		}
	}

	std::cout << maxWord << ' ' << maxSum;
	outputFile << maxWord << ' ' << maxSum;

	return 0;
}
