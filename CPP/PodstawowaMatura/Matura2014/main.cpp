#include <iostream>
#include <fstream>

// =================== CONFIGURATION ===================

const int FILE_LENGTH = 1000;

const std::string INPUT_FILE_NAME = "";
const std::string OUTPUT_FILE_NAME = "";

// =====================================================


bool IsNumberMultiple(int firstNum, int secondNum) {
    return firstNum % secondNum == 0 || secondNum % firstNum == 0;
}

int SumNumDigitals(int num) {
    int sum = 0;

    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }

    return sum;
}

bool SumNumEquals(int* firstNum, int* secondNum) {
    return SumNumDigitals(*firstNum) == SumNumDigitals(*secondNum);
}

int* HigerNumOfTwo(int* firstNum, int* secondNum) {
    if (*firstNum > *secondNum) { return firstNum; }
    return secondNum;
}

bool EqFirst(int* firstNum, int* secondNum) {
    for (int i = 2; i <= *HigerNumOfTwo(firstNum, secondNum); i++) {
        if (*firstNum % i == 0 || *secondNum % i == 0) { return false; }
    }
    return true;
}

void ParseNumber(std::string* word, int* firstNum, int* secondNum) {
    bool parsingFirstNum = true;
    for (int i = 0; i < (*word).size(); i++) {
        if (parsingFirstNum) {
            if ((*word)[i] == ' ') { parsingFirstNum = !parsingFirstNum; continue;}
            *firstNum *= 10;
            *firstNum += (int)(*word)[i] - 48;
        }

        else {
            *secondNum *= 10;
            *secondNum += (int)(*word)[i] - 48;
        }
    }
}

int main() {
    std::fstream inputFile, outputFile;

    std::string tempWord;
    int firstNumTemp, secondNumTemp;

    inputFile.open(INPUT_FILE_NAME, std::ios::in);
    outputFile.open(OUTPUT_FILE_NAME, std::ios::out);

    for (int i = 0; i < FILE_LENGTH; i++) {
        inputFile >> tempWord;

        ParseNumber(&tempWord, &firstNumTemp, &secondNumTemp);
        std::cout << firstNumTemp << ", " << secondNumTemp; 
    }

    inputFile.close();
    outputFile.close();

    return 0;
}