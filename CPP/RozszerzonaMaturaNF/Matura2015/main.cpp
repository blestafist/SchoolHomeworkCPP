#include <iostream>
#include <fstream>

// ================================ CONFIGURATION ===================================

const std::string INPUT_FILE_NAME = "liczby.txt"; // input file name here
const std::string OUTPUT_FILE_NAME = "winik4.txt"; // output file name here

// =================================================================================

// minimal wrapper for program (remove comment)
bool IsCountOfZerosMore(const std::string& str)
{
    int counter = 0;
    for(char c : str) {
        c == '0' ? counter++ : counter--;
    }
    return counter > 0; // сука хули они сдохли заебали
}


bool IsNewBinaryHigher(const std::string& binaryOld, const std::string& binaryNew) 
{
	if (binaryNew.size() < binaryOld.size()) { return false; }
	if (binaryNew.size() > binaryOld.size()) { return true; }

	for (int i = 0; i < binaryNew.size(); i++) {
		if (binaryNew[i] == '0' && binaryOld[i] == '1') { }
	}

	return false;
} 


int main() {
	std::ifstream inputFile (INPUT_FILE_NAME);
	std::ofstream outputFile;

	int divideBy2Counter = 0, divideBy8Counter = 0;

	std::string tempWord; // string / int (change on need)
	// int tempNum;
   

	while (inputFile >> tempWord) {
		inputFile >> tempWord;
        if(IsCountOfZerosMore(tempWord)) { std::cout << tempWord <<"\n"; outputFile << tempWord <<"\n"; }
		// here place the conditions for nums / strs checking	

		if (tempWord[tempWord.size() - 1] == '0') { 
			divideBy2Counter++;

			if (tempWord[tempWord.size() - 2] == '0' && tempWord[tempWord.size() - 3] == '0') {
				divideBy8Counter++;
			}
		}
	}

	inputFile.close();
	
	outputFile.open(OUTPUT_FILE_NAME);

	std::cout <<"zadanie 1\n";

	// write answers
	
	outputFile.close();

	return 0;
}
