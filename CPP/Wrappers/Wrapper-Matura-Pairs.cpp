#include <iostream>
#include <fstream>
#include <vector>

// ================================ CONFIGURATION ===================================

std::string INPUT_FILE_NAME = ""; // input file name here
std::string OUTPUT_FILE_NAME = ""; // output file name here

int FILE_LENGTH = 1000; // lenth of input data array (num of pairs)

// =================================================================================

// minimal wrapper for program (remove comment)

// two value struct 
struct Pair {
    public:
        int x;
        int y;

        Pair(int _x, int _y) {
            x = _x;
            y = _y;
        }
};

int main() {
	std::ifstream inputFile(INPUT_FILE_NAME);
	std::ofstream outputFile; // not opening it yet

	int firstNum, secondNum;
    std::vector<Pair> pairs; // vector, that'll be containing pairs of numbers

	for (int i = 0; i < FILE_LENGTH; i++) {
		inputFile >> firstNum >> secondNum;

        pairs.push_back({firstNum, secondNum});	
	}

	inputFile.close();
	
	outputFile.open(OUTPUT_FILE_NAME);

	// write answers
    for (int i = 0; i < pairs.size(); i++) {
        // program logic
    }
	
	outputFile.close();

	return 0;
}
