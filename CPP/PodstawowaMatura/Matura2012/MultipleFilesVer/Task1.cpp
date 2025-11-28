#include <iostream>
#include <fstream>

// ================================ CONFIGURATION ===================================

std::string INPUT_FILE_NAME = "cyfry.txt"; // input file name here
std::string OUTPUT_FILE_NAME = "zadanie4.txt"; // output file name here

int FILE_LENGTH = 1000; // lenth of input data array

// =================================================================================


bool NumIsEven(int* num) { // func checks if given num is Even (parzyste)
    return *num % 2 == 0;
}


int main() {
	std::fstream inputFile, outputFile;
	int tempWord;
	
	int evenCounter = 0;

	inputFile.open(INPUT_FILE_NAME, std::ios::in);


	for (int i = 0; i < FILE_LENGTH; i++) {
		inputFile >> tempWord;
		
		if (NumIsEven(&tempWord)) { evenCounter++; }
		// here place the conditions for nums / strs checking	
	}

	inputFile.close();
	
	outputFile.open(OUTPUT_FILE_NAME, std::ios::out);
	
	// write answers
	std::cout << "Zadanie 1." << std::endl << "Ilość parzystych: " << evenCounter << std::endl << std::endl;
	outputFile << "Zadanie 1." << std::endl << "Ilość parzystych: " << evenCounter << std::endl << std::endl;
	outputFile.close();

	return 0;
}
