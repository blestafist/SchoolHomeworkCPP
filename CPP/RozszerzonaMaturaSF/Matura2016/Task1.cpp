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

void ParseFile(bool (&arr)[DIMENSIONS_X][DIMENSIONS_Y]) {
    std::ifstream inputFile (INPUT_FILE_NAME);
    if (!inputFile) { throw std::runtime_error("Error while opening input file!"); }
    char currC;

    for (int y = 0; y < DIMENSIONS_Y; y++) {
        for (int x = 0; x < DIMENSIONS_X; x++) {
            inputFile >> currC;
            currC == 'X' ? arr[x][y] = true : arr[x][y] = false; 
        }
    }
}


int SumOfNeighbors(const bool (&arr)[DIMENSIONS_X][DIMENSIONS_Y], int indexX, int indexY) {
    int aliveNeightbors = 0;

    for (int i = 0; i < 8; i++) { // counting all alive neightbors
        int nx = (indexX + velocityX[i] + DIMENSIONS_X) % DIMENSIONS_X;
        int ny = (indexY + velocityY[i] + DIMENSIONS_Y) % DIMENSIONS_Y;

        if (arr[nx][ny]) { aliveNeightbors++; }
    }

    return aliveNeightbors;
}


void SimulateNextGen(bool (&arr)[DIMENSIONS_X][DIMENSIONS_Y]) {
    bool helperArr[DIMENSIONS_X][DIMENSIONS_Y] {};

    for (int y = 0; y < DIMENSIONS_Y; y++) {
        for (int x = 0; x < DIMENSIONS_X; x++) {
            int aliveNeightbors = SumOfNeighbors(arr, x, y);
            helperArr[x][y] = false;

            // now calculating
            if ((aliveNeightbors == 3 && !arr[x][y]) || ((aliveNeightbors == 2 || aliveNeightbors == 3) && arr[x][y])) {
                helperArr[x][y] = true;
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
    bool mainArr[DIMENSIONS_X][DIMENSIONS_Y] {};

    std::ofstream outputFile (OUTPUT_FILE_NAME);
    if (!outputFile) { std::cerr << "Error while opening output file!"; return -1; }
    auto Print = [&] (auto&&... args) { (std::cout << ... << args) << "\n"; (outputFile << ... << args) << "\n"; };

    ParseFile(mainArr);
    for (int i = 0; i < 36; i++) {
        SimulateNextGen(mainArr);
    }

    Print("1. Ilość sąsiadów: ", SumOfNeighbors(mainArr, 18, 1));
}
