#include <iostream>
#include <fstream>

// ================================ CONFIGURATION ===================================

const std::string INPUT_FILE_NAME = "dane.txt"; // input file name here
const std::string OUTPUT_FILE_NAME = "wyniki6.txt"; // output file name here

const int DIMENSIONS_X = 320;
const int DIMENSIONS_Y = 200;

// ==================================================================================

void ParseFile(unsigned char (&arr)[DIMENSIONS_X][DIMENSIONS_Y]) {
    std::ifstream inputFile (INPUT_FILE_NAME);
    if (!inputFile) { std::cerr << "Error while opening output file!"; throw -1; }

    short current;

    for (int x = 0; x < DIMENSIONS_X; x++) {
        for (int y = 0; y < DIMENSIONS_Y; y++) {
            inputFile >> current;
            arr[x][y] = current;
        }
    }
}


// a helper func, not used in real program
void PrintArr(const unsigned char (&arr)[DIMENSIONS_X][DIMENSIONS_Y]) {
    for (int x = 0; x < DIMENSIONS_X; x++) {
        for (int y = 0; y < DIMENSIONS_Y; y++) {
            std::cout << (short)arr[x][y] << ' ';
        }

        std::cout << "\n";
    }
}

bool ContrastNeightboor(const unsigned char (&arr)[DIMENSIONS_X][DIMENSIONS_Y]) {
    // first define the conditions for checking

    for (int x = 0; x < DIMENSIONS_X; x++) {
        for (int y = 0; y < DIMENSIONS_Y; y++) {
            
        }
    }

    return false;
}

int main() {
    unsigned char mainArr[DIMENSIONS_X][DIMENSIONS_Y];
    ParseFile(mainArr);
    

}