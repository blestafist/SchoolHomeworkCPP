#include <iostream>
#include <fstream>
#include <vector>

// ================================ CONFIGURATION ===================================

std::string INPUT_FILE_NAME = "PARY_LICZB.TXT"; // input file name here
std::string OUTPUT_FILE_NAME = "ZADANIE5.TXT"; // output file name here

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

// end of structs

// addictional funcs


bool MultipleNumOfTwo(int* x, int* y) {
    if (*x == 0 || *y == 0) { return false; } 

    if (*x > *y) { return *x % *y == 0; }
    return *y % *x == 0;
}

bool HighestBothDivider(int x, int y) {
    if (x == 0 || y == 0) { return false; }
    while (x != y) {
        if (x > y) {
            x -= y;
        }

        else {
            y -= x;
        }
    }

    return x == 1;
}

int SumNum(int x) {
    int result = 0;
    
    while (x > 0) {
        result += x % 10;
        x /= 10;
    }

    return result;
}

bool SumNumEquals(int* x, int* y) {
    return SumNum(*x) == SumNum(*y);
}

// program entry point 

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
    int countA = 0, countB = 0, countC = 0;

	// write answers
    for (int i = 0; i < pairs.size(); i++) {
        if (MultipleNumOfTwo(&pairs[i].x, &pairs[i].y)) { countA++; }
        if (HighestBothDivider(pairs[i].x, pairs[i].y)) { countB++; }
        if (SumNumEquals(&pairs[i].x, &pairs[i].y)) { countC++; }
    }

    std::cout << "Zadanie A: " << countA << std:: endl;
    std::cout << "Zadanie B: " << countB << std:: endl;
    std::cout << "Zadanie C: " << countC << std:: endl;

    outputFile << "Zadanie A: " << countA << std:: endl;
    outputFile << "Zadanie B: " << countB << std:: endl;
    outputFile << "Zadanie C: " << countC << std:: endl;

	
	outputFile.close();

	return 0;
}
