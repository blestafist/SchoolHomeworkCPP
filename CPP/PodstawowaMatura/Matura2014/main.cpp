#include <iostream>
#include <fstream>
#include <vector>

// ================================ CONFIGURATION ===================================

std::string INPUT_FILE_NAME = "PARY_LICZB.TXT"; // input file name here
std::string OUTPUT_FILE_NAME = "ZADANIE5.TXT"; // output file name here

int FILE_LENGTH = 1000; // lenth of input data array

// =================================================================================


struct KeyValuePair { // struct for a pair of numbers
    public:
        int key;
        int value;

        KeyValuePair(int _key, int _value) {
            key = _key;
            value = _value;
        }
    
};


// some funcs definitions (minimal)



int main() {
	std::fstream inputFile, outputFile;
	std::string tempWord;

    std::vector<KeyValuePair> pairs = {};

	inputFile.open(INPUT_FILE_NAME, std::ios::in);


	for (int i = 0; i < FILE_LENGTH; i++) {
		int tempKey, tempVal;

        inputFile >> tempKey >> tempVal;
        pairs.push_back({tempKey, tempVal});

        std::cout << pairs[i].key << ": " << pairs[i].value << std::endl;
	}

	inputFile.close();
	
	outputFile.open(OUTPUT_FILE_NAME, std::ios::out);

	// write answers
	
	outputFile.close();

	return 0;
}
