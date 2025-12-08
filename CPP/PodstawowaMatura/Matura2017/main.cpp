#include <iostream>
#include <fstream>

// ================================ CONFIGURATION ===================================

std::string INPUT_FILE_NAME = "liczby.txt"; // input file name here
std::string OUTPUT_FILE_NAME = "wyniki4.txt"; // output file name here

int FILE_LENGTH = 1000; // lenth of input data array

// =================================================================================

// triple struct
struct ThreeNums {
    int first;
    int second; 
    int third;

    bool IncreasingOrder() {
        return first < second && second << third;
    }
};


int main() {
	std::ifstream inputFile(INPUT_FILE_NAME);
	std::ofstream outputFile;
    short increasingCount = 0;

	int tempWord; // string / int (change on need)

	for (int i = 0; i < FILE_LENGTH; i++) {
        ThreeNums nums;
		inputFile >> nums.first >> nums.second >> nums.third;
        if (nums.IncreasingOrder() == true) { increasingCount++; }
        


		// here place the conditions for nums / strs checking	
	}

	inputFile.close();
	
	outputFile.open(OUTPUT_FILE_NAME);

	// write answers
	
	outputFile.close();

	return 0;
}
