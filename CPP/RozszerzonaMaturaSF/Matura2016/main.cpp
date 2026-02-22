#include <iostream>
#include <fstream>
#include <stdexcept>

// =========================== CONFIGURATION ===========================

const std::string INPUT_FILE_NAME = "gra.txt";
const std::string OUTPUT_FILE_NAME = "wynik4.txt";

const int DIMENSIONS_X = 20;
const int DIMENSIONS_Y = 12;

// =====================================================================

void ParseFile(char (&arr)[DIMENSIONS_X][DIMENSIONS_Y]) {
    std::ifstream inputFile (INPUT_FILE_NAME);
    if (!inputFile) { throw std::runtime_error("Error while opening input file!"); }

    for (int y = 0; y < DIMENSIONS_Y; y++) {
        for (int x = 0; x < DIMENSIONS_X; x++) {
            inputFile >> arr[x][y];
        }
    }
}


// ! Not used in code directly, just for debugging
void PrintArr(const char (&arr)[DIMENSIONS_X][DIMENSIONS_Y]) {
    for (int y = 0; y < DIMENSIONS_Y; y++) {
        for (int x = 0; x < DIMENSIONS_X; x++) {
            std::cout << arr[x][y] << ' ';
        }
        std::cout << "\n";
    } 
}


int main() {
    char mainArr[DIMENSIONS_X][DIMENSIONS_Y];
    ParseFile(mainArr);
    PrintArr(mainArr);
}