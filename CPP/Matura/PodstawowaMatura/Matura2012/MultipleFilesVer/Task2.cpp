#include <iostream>
#include <fstream>
#include <limits.h>


// ================================ CONFIGURATION ===================================

std::string INPUT_FILE_NAME = "cyfry.txt"; // input file name here
std::string OUTPUT_FILE_NAME = "zadanie4.txt"; // output file name here

int FILE_LENGTH = 1000; // lenth of input data array

// =================================================================================


// minimal wrapper for program (remove comment)

int SumDigits(int num) {
    int sum = 0;

    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }

    return sum;
}


int main() {
	std::fstream inputFile, outputFile;
	int tempNum;
	int highest = INT_MIN, lowest = INT_MAX;
	int highestNum, lowestNum;

	inputFile.open(INPUT_FILE_NAME, std::ios::in);


	for (int i = 0; i < FILE_LENGTH; i++) {
		inputFile >> tempNum;

		if (SumDigits(tempNum) > highest) { highest = SumDigits(tempNum); highestNum = tempNum; }
        	if (SumDigits(tempNum) < lowest) { lowest = SumDigits(tempNum); lowestNum = tempNum; }

		
		// here place the conditions for nums / strs checking	
	}

	inputFile.close();
	
	outputFile.open(OUTPUT_FILE_NAME, std::ios::app);
	

	std::cout << "Zadanie B. Największa suma cyfr w liczbie: " << highestNum << std::endl;
	std::cout << "Najmniejsza suma cyfr w liczbie: " << lowestNum << std::endl << std::endl;

    	outputFile << "Zadanie B. Największa suma cyfr w liczbie: " << highestNum << std::endl;
    	outputFile << "Najmniejsza suma cyfr w liczbie: " << lowestNum << std::endl << std::endl;
	// write answers
	
	outputFile.close();

	return 0;
}
