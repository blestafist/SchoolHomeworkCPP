#include <iostream>
#include <fstream>
#include <vector>

// ================================ CONFIGURATION ===================================

const std::string INPUT_FILE_NAME = "slowa.txt"; // input file name here
const std::string SECOND_INPUT_FILE_NAME = "nowe.txt"; // second input file name
const std::string OUTPUT_FILE_NAME = "wynik5.txt"; // output file name here

const int FILE_LENGTH = 1000; // lenth of input data array

// =================================================================================

// structs
struct Pair {
    public:
        int x;
        int y;
};


// addictional funcs

std::string ReverseWord(std::string word) {
    std::string result = "";
    result.reserve(word.size()); // reserve memory 

    for (int i = word.size() - 1; i >= 0; i--) {
        result += word[i];
    }

    return result;
}

Pair WordAndReverseContainsTimesInArray(const std::vector<std::string>& vec, std::string word) {
    int wordTimes = 0, wordCopyTimes = 0;

    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == word) { wordTimes++; }
        else if (vec[i] == ReverseWord(word)) { wordCopyTimes++; }
    }

    Pair pair;
    pair.x = wordTimes;
    pair.y = wordCopyTimes;

    return pair;
}

// entry point
int main() {
	std::ifstream inputFile(INPUT_FILE_NAME);
    std::ifstream secondInputFile;
	std::ofstream outputFile;

    std::vector<std::string> words;

	std::string tempWord; // string / int (change on need)
    int array[12] {};

	for (int i = 0; i < FILE_LENGTH; i++) {
		inputFile >> tempWord;
        array[tempWord.size() - 1]++;

        words.push_back(tempWord);

		// here place the conditions for nums / strs checking	
	}

	inputFile.close();
	
	outputFile.open(OUTPUT_FILE_NAME);

    std::cout << "Zadanie 5.1 \n";
    outputFile << "Zadanie 5.1 \n";

	// write answers
    for (int i = 0; i < 12; i++) {
        std::cout << i + 1 << " → " << array[i] << "\n";
        outputFile << i + 1 << " → " << array[i] << "\n";
    }

    secondInputFile.open(SECOND_INPUT_FILE_NAME);

    std::cout << "\n\nZadanie 5.2 \n";
    outputFile << "\n\nZadanie 5.2 \n";

    for (int i = 0; i < 25; i++) {
        secondInputFile >> tempWord;
        Pair pair;
        pair = WordAndReverseContainsTimesInArray(words, tempWord);

        std::cout << tempWord << " → " << pair.x << " → " << pair.y << std::endl;
        outputFile << tempWord << " → " << pair.x << " → " << pair.y << std::endl;
    }

	secondInputFile.close();
	outputFile.close();

	return 0;
}
