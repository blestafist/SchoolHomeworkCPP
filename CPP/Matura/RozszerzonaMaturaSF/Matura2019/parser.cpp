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


void DisplayArr(char (&arr)[DIMENSIONS][DIMENSIONS]) { // func is not used in answers, just for debugging
    for (int i = 0; i < DIMENSIONS; i++) {
        for (int j = 0; j < DIMENSIONS; j++) {
            std::cout << arr[i][j];
        }

        std::cout << "\n";
    }

    std::cout << "\n";
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

    return grassCounter >= (PERCENTAGE_OF_GRASS) * (DIMENSIONS * DIMENSIONS);
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
        for (int j = 0; j < maxSquare + 1; j++) {
            for (int d = 0; d < maxSquare + 1; d++) {
                if (arr[j][d] == 'X') { return maxSquare; }
            }
        }

        ++maxSquare;
    }

    return maxSquare;
}
