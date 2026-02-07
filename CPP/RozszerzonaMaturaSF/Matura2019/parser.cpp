#include "parser.h"

// other libs included in header

void ParseNext(std::ifstream& inputFile, char (&outputArr)[DIMENSIONS][DIMENSIONS]) { // arr is a pointer on the first element
    std::string line;

    for (int i = 0; i < DIMENSIONS; i++) {
        inputFile >> line;

        for (int j = 0; j < DIMENSIONS; j++ ) {
            outputArr[i][j] = line[j];
        }
    }
}


bool IsGrass(const char (&arr)[DIMENSIONS][DIMENSIONS]) {
    int grassCounter = 0;

    for (int i = 0; i < DIMENSIONS; i++) {
        for (int j = 0; j < DIMENSIONS; j++) {
            if (arr[i][j] == '*') {
                grassCounter++;
            }
        }
    }

    // calculating limits. 70% of 900 is 630

    return grassCounter >= 630;
}

bool SameAfterReverse(const char (&arr)[DIMENSIONS][DIMENSIONS]) { // literally checking if 2d arr is palidromic
    for (int i = 0; i < DIMENSIONS / 2; i++) {
        for (int j = 0; j < DIMENSIONS; j++) {
            if (arr[i][j] != arr[DIMENSIONS - 1 - i][DIMENSIONS - 1 - j]) { return false; }
        }
    }

    return true; // my alghoritm works only when eDIMENSIONS % 2 == 0 (even)
}


short MaxSquare(const char (&arr)[DIMENSIONS][DIMENSIONS]) {
    // need to make the biggest square from [0][0]

    short maxSquare = 0;

    for (int i = 0; i < DIMENSIONS; i++) {
        
    }

    return maxSquare;
}
