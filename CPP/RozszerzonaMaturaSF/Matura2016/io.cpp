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


// ! Not used in code directly, just for debugging
void PrintArr(const char (&arr)[DIMENSIONS_X][DIMENSIONS_Y]) {
    for (int y = 0; y < DIMENSIONS_Y; y++) {
        for (int x = 0; x < DIMENSIONS_X; x++) {
            std::cout << arr[x][y] << ' ';
        }
        std::cout << "\n";
    } 
}

void SimulateNextGen(char (&arr)[DIMENSIONS_X][DIMENSIONS_Y]) {
    char helperArr[DIMENSIONS_X][DIMENSIONS_Y];

    for (int y = 0; y < DIMENSIONS_Y; y++) {
        for (int x = 0; x < DIMENSIONS_X; x++) {
            int aliveNeightbors = 0;
            helperArr[x][y] = '.';

            for (int i = 0; i < 8; i++) { // counting all alive neightbors
                int nx = x + velocityX[i];
                int ny = y + velocityY[i];

                if (nx < 0 || nx >= DIMENSIONS_X || ny < 0 || ny >= DIMENSIONS_Y) { continue; }

                if (arr[nx][ny] == 'X') { aliveNeightbors++; }
            }

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
    PrintArr(mainArr);
}