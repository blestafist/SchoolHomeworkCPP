#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

// ================================== CONFIGURATION ==================================

const std::string INPUT_FILE_NAME = "pary_przyklad.txt";
const std::string OUTPUT_FILE_NAME = "wyniki3.txt";

// ===================================================================================

int BothOcc(const std::string& str1, const std::string& str2) {
	int result = 0;
	std::string allUnique = "";

	for (char c : str1) {
		if (allUnique.find(c) == std::string::npos) {
			allUnique += c;
		}
	}

	for (char c : allUnique) {
		int occOne = std::count(str1.begin(), str1.end(), c);
		int occTwo = std::count(str2.begin(), str2.end(), c);

		result += std::min(occOne, occTwo);
	}

	return result; // temp value to change
}

int main() {
	std::ifstream inputFile (INPUT_FILE_NAME);
	if (!inputFile) { std::cerr << "Error while opening input file!"; return 1; }

	std::ofstream outputFile (OUTPUT_FILE_NAME);

	std::string word1, word2, maxWord;
	int maxSum = -1;

	while (inputFile >> word1 >> word2) {
		int curr = BothOcc(word1, word2);
		if (maxSum == -1 || curr > maxSum) {
			maxSum = curr;
			maxWord = word1 + ' ' + word2;
		}
	}

	std::cout << maxWord << ' ' << maxSum;
	outputFile << maxWord << ' ' << maxSum;

	return 0;
}
