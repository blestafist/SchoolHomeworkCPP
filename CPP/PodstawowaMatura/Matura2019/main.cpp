#include <iostream>
#include <fstream>
#include <vector>

// ================================ CONFIGURATION ===================================

const std::string INPUT_FILE_NAME = "dane.txt"; // input file name here
const std::string OUTPUT_FILE_NAME = "wyniki6.txt"; // output file name here

const int FILE_LENGTH = 1000; // lenth of input data array

// =================================================================================

bool IsMan(const std::string* pesel) {
	char overLast = (*pesel)[(*pesel).size() - 2] - 48;
	return overLast % 2 == 1;
}

bool IsBornInNovember(const std::string* pesel) {
	return ((*pesel)[2] == '1' && (*pesel)[3] == '1') || ((*pesel)[2] == '3' && (*pesel)[3] == '1');
}

bool IsCorrect(const std::string* pesel) {
	short result;

	result = (1 * (*pesel)[0]) + (3 * (*pesel)[1]) + (7 * (*pesel)[2]) + (9 * (*pesel)[3]) + (1 * (*pesel)[4]) + (3 * (*pesel)[5]) + (7 * (*pesel)[6]) + (9 * (*pesel)[7]) + (1 * (*pesel)[8]) + (3 * (*pesel)[9]) + (*pesel)[10];

	return result % 10 == 0;
}


int main() {
	std::ifstream inputFile(INPUT_FILE_NAME);
	std::ofstream outputFile;

	std::string tempWord; // string cause all operation on pesel will be better to make on strs

	short manCount = 0, womanCount = 0, bornInNovemberCount = 0;
	std::vector<std::string> incorrectPesels;

	std::cout << CharToByte('5');

	for (int i = 0; i < FILE_LENGTH; i++) {
		inputFile >> tempWord;

		if (IsMan(&tempWord)) { manCount++; }
		else { womanCount++; }

		if (IsBornInNovember(&tempWord)) { bornInNovemberCount++; }
		if (!IsCorrect(&tempWord)) { incorrectPesels.push_back(tempWord); }	
	}

	inputFile.close();
	
	outputFile.open(OUTPUT_FILE_NAME);

	std::cout << "Zadanie 6.1. Liczba kobiet: " << womanCount << "Liczba mężczyzn: " << manCount << "\n\n";

	std::cout << "Zadanie 6.2. Liczba osób, urodzonych w listopadzie: " << bornInNovemberCount << "\n\n";

	std::cout << "Zadanie 6.3. Blędne numery pesel: \n";
	for (int i = 0; i < incorrectPesels.size(); i++) {
		std::cout << incorrectPesels[i] << "\n";
	}
	
	outputFile.close();

	return 0;
}
