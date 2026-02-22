#include <iostream>
#include <fstream>
#include <stdexcept>

// =========================== CONFIGURATION ===========================

const std::string INPUT_FILE_NAME = "gra.txt";
const std::string OUTPUT_FILE_NAME = "wyniki5.txt";

const int DIMENSIONS_X = 20;
const int DIMENSIONS_Y = 12;

int velocityX[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int velocityY[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

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

int CountAlive(const char (&arr)[DIMENSIONS_X][DIMENSIONS_Y]) {
    int alive = 0;

    for (int y = 0; y < DIMENSIONS_Y; y++) {
        for (int x = 0; x < DIMENSIONS_X; x++) {
            if (arr[x][y] == 'X') { alive++; }
        }
    }

    return alive;
}


void SimulateNextGen(char (&arr)[DIMENSIONS_X][DIMENSIONS_Y]) {
    char helperArr[DIMENSIONS_X][DIMENSIONS_Y] {};

    for (int y = 0; y < DIMENSIONS_Y; y++) {
        for (int x = 0; x < DIMENSIONS_X; x++) {
            int aliveNeightbors = SumOfNeightbors(arr, x, y);
            helperArr[x][y] = '.';

            // now calculating
            if ((aliveNeightbors == 3 && arr[x][y] == '.') || ((aliveNeightbors == 2 || aliveNeightbors == 3) && arr[x][y] == 'X')) {
                helperArr[x][y] = 'X';
            }
        }
    }

    // swap arrays
    for (int y = 0; y < DIMENSIONS_Y; y++) {
        for (int x = 0; x < DIMENSIONS_X; x++) {
            arr[x][y] = helperArr[x][y];
        }
    }
    // no need to return
}


int main() {
    char mainArr[DIMENSIONS_X][DIMENSIONS_Y];
    ParseFile(mainArr);

    int prevAlive = -1;

    for (int i = 0; i < 99; i++) {
        if (prevAlive == CountAlive(mainArr)) { std::cout << "Pokolenie: " << i + 1 << "\nLiczba komorek: " << prevAlive; return 0; }
        prevAlive = CountAlive(mainArr);
        SimulateNextGen(mainArr);
    }

    std::cout << "Not found";
}