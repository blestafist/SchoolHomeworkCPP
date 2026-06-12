#include <iostream>
#include <fstream>
#include <vector>


// ================================== CONFIGURATION ==================================

const std::string INPUT_FILE_NAME = "korpo_przyklad.txt";
const std::string OUTPUT_FILE_NAME = "wyniki4.txt";

// ===================================================================================


int main() {
	std::ifstream inputFile (INPUT_FILE_NAME);
	if (!inputFile) { std::cerr << "Error while opening input file!"; return 1; }

	std::ofstream outputFile (OUTPUT_FILE_NAME);
	size_t boss;

	std::vector<size_t> cnt (50001, 0);

	while (inputFile >> boss) {
			cnt[boss]++;
	}

	size_t bossForNobody = 0;

	for (size_t i = 1; i < cnt.size(); ++i) {
		if (cnt[i] == 0) {
			++bossForNobody;
		}
	}

	std::cout << bossForNobody << "\n";

	return 0;
}
