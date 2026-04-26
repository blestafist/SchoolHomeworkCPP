#include <iostream>
#include <fstream>
#include <algorithm>

// ================================ CONFIGURATION ===================================

const std::string INPUT_FILE_NAME = "liczby.txt"; // input file name here
const std::string OUTPUT_FILE_NAME = "winik4.txt"; // output file name here

const short FILE_LENGTH = 1000;

// =================================================================================

bool AreZeroesMajority (const std::string& binaryStr) {
    size_t zeroesCounter = std::count(binaryStr.begin(), binaryStr.end(), '0');
	return zeroesCounter > (binaryStr.size() / 2);
}


bool IsBinarySmaller (const std::string& bin1, const std::string& bin2) { // true → second value greater, first smaller
	if (bin1.size() != bin2.size()) { return bin1.size() < bin2.size(); }
	return bin1 < bin2;
}


int main() {
	std::ifstream inputFile (INPUT_FILE_NAME);
	std::ofstream outputFile;

	if (!inputFile.is_open()) { std::cout << "Error while opening the file"; }

	int divideBy2Counter = 0, divideBy8Counter = 0, zeroGreaterOneCounter = 0;

	std::string tempWord; // string / int (change on need)
	// int tempNum;

    short minLine, maxLine;
    std::string minBin, maxBin;

	for (int i = 0; i < FILE_LENGTH; i++) {
        inputFile >> tempWord;
        if (i == 0) { minBin = tempWord; maxBin = tempWord; }
        if(IsCountOfZerosMore(tempWord)) { zeroGreaterOneCounter++; }
		// here place the conditions for nums / strs checking

		if (tempWord[tempWord.size() - 1] == '0') {
			divideBy2Counter++;

			if (tempWord[tempWord.size() - 2] == '0' && tempWord[tempWord.size() - 3] == '0') {
				divideBy8Counter++;
			}
		}

        if (!CompareTwoBinary(maxBin, tempWord)) {
              maxBin = tempWord;
              maxLine = i;
            }

        if (CompareTwoBinary(minBin, tempWord)) {
            minBin = tempWord;
            minLine = i;
        }

    }



	inputFile.close();

	outputFile.open(OUTPUT_FILE_NAME);

	std::cout << "1. " << zeroGreaterOneCounter;
	outputFile << "1. " << zeroGreaterOneCounter;



	std::cout << "\n\n2. 2: " << divideBy2Counter << "\n8: " << divideBy8Counter;
	outputFile << "\n\n2. 2: " << divideBy2Counter << "\n8: " << divideBy8Counter;

	std::cout << "\n\n3. " << minLine + 1 << ": " << minBin;
	std::cout << "\n" << maxLine + 1 << ": " << maxBin;

	outputFile << "\n\n3. " << minLine + 1 << ": " << minBin;
	outputFile << "\n" << maxLine + 1 << ": " << maxBin;

	// write answers

	outputFile.close();

	return 0;
}
