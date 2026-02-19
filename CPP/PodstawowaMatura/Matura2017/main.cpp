#include <iostream>
#include <fstream>
#include <utility>

// ================================ CONFIGURATION ===================================

std::string INPUT_FILE_NAME = "liczby.txt"; // input file name here
std::string OUTPUT_FILE_NAME = "wyniki4.txt"; // output file name here

int FILE_LENGTH = 1000; // lenth of input data array

// =================================================================================

int GCD(int a, int b) {
	while (b) {
		a %= b;
		std::swap(a, b);
	}

	return a;
}

int SumNum(int num) {
	int result = 0;

	while (num > 0) {
		result += num % 10;
		num /= 10;
	}

	return result;
}


// triple struct
struct ThreeNums {
    int first;
    int second; 
    int third;

    bool IncreasingOrder() {
        return first < second && second < third;
    }

	int SumDigitsOfThree() {
		return SumNum(first) + SumNum(second) + SumNum(third);
	}

	bool SumEquals35() {
		return SumDigitsOfThree() == 35;
	}
};


int main() {
	std::ifstream inputFile(INPUT_FILE_NAME);
	std::ofstream outputFile;
    unsigned short increasingCount = 0, sumDigits, sumEquals35 = 0, highestLinesCount = 0;
	int NWDSum = 0, highest = 0;

	int arraySumsDigits[FILE_LENGTH];

	int tempWord; // string / int (change on need)

	for (int i = 0; i < FILE_LENGTH; i++) {
        ThreeNums nums;
		inputFile >> nums.first >> nums.second >> nums.third;

		sumDigits = nums.SumDigitsOfThree();

        if (nums.IncreasingOrder() == true) { increasingCount++; }
        
		NWDSum += GCD(nums.first, GCD(nums.second, nums.third)); // 2nd
		if (nums.SumEquals35()) { sumEquals35++; }

		arraySumsDigits[i] = sumDigits;

		if (highest < sumDigits) { highest = sumDigits; }
	}

	for (int i = 0; i < FILE_LENGTH; i++) {
		if (arraySumsDigits[i] == highest) { highestLinesCount++; }
	}
	inputFile.close();
	
	outputFile.open(OUTPUT_FILE_NAME);

	std::cout << "Zadanie 4.1: Ilość wierszów z liczbami rosnącymi: " << increasingCount << "\n\n";
	outputFile << "Zadanie 4.1: Ilość wierszów z liczbami rosnącymi: " << increasingCount << "\n\n";
	
	std::cout << "Zadanie 4.2: Suma NWD: " << NWDSum << "\n\n";
	outputFile << "Zadanie 4.2: Suma NWD: " << NWDSum << "\n\n";

	std::cout << "Zadanie 4.3: \nLiczba wierszy, których suma cyfr jest równa 35: " << sumEquals35 << "\nNajwiększa suma: " << highest << "\nLiczba wystąpień największej sumy: " << highestLinesCount; 
	outputFile << "Zadanie 4.3: \nLiczba wierszy, których suma cyfr jest równa 35: " << sumEquals35 << "\nNajwiększa suma: " << highest << "\nLiczba wystąpień największej sumy: " << highestLinesCount; 
	
	outputFile.close();

	return 0;
}
