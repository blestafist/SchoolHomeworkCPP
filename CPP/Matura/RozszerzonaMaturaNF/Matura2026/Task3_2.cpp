#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
#include <algorithm>

// ================================== CONFIGURATION ==================================

const std::string INPUT_FILE_NAME = "pary_przyklad.txt";
const std::string OUTPUT_FILE_NAME = "wyniki3.txt";

// ===================================================================================

int BothOcc(const std::string& str1, const std::string& str2) {
	int result = 0;
	std::unordered_set<char> allUnique;

	std::string source = str1.size() < str2.size() ? str1 : str2;
	for (char c : source) {
		if (!allUnique.count(c)) {
			allUnique.emplace(c);
		}
	}

	for (char c : allUnique) {
		int occOne = std::count(str1.begin(), str1.end(), c);
		int occTwo = std::count(str2.begin(), str2.end(), c);

		result += std::min(occOne, occTwo);
	}

	return result;
}

int main() {
	std::ifstream inputFile (INPUT_FILE_NAME);
	if (!inputFile) { std::cerr << "Error while opening input file!"; return 1; }

	std::ofstream outputFile (OUTPUT_FILE_NAME);
	auto Print = [&] (auto&&... args) { (std::cout << ... << args) << "\n"; (outputFile << ... << args) << "\n"; };

	std::string word1, word2, maxWord;
	int maxSum = -1;

	while (inputFile >> word1 >> word2) {
		int curr = BothOcc(word1, word2);
		if (maxSum == -1 || curr > maxSum) {
			maxSum = curr;
			maxWord = word1 + ' ' + word2;
		}
	}

	Print(maxWord, " → ", maxSum);

	return 0;
}
