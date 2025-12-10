#include <iostream>
#include <fstream>

// ================================ CONFIGURATION ===================================

std::string INPUT_FILE_NAME = "liczby.txt"; // input file name here
std::string OUTPUT_FILE_NAME = "wyniki4.txt"; // output file name here

int FILE_LENGTH = 1000; // lenth of input data array

// =================================================================================

int GCD();
int SumNum();

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

int GCD(int x, int y) {
	int temp;
	while (y != 0) {
		temp = x % y;
		x = y;
		y = temp;
	}

	return x;
}

int SumNum(int num) {
	int result = 0;

	while (num > 0) {
		result += num % 10;
		num /= 10;
	}

	return result;
}

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
		
	}

	inputFile.close();
	
	outputFile.open(OUTPUT_FILE_NAME);

	// write answers
	
	outputFile.close();

	return 0;
}
