#include <ios>
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


int SumOfNeightbors(const char (&arr)[DIMENSIONS_X][DIMENSIONS_Y], int indexX, int indexY) {
    int aliveNeightbors = 0;

    for (int i = 0; i < 8; i++) { // counting all alive neightbors
        int nx = (indexX + velocityX[i] + DIMENSIONS_X) % DIMENSIONS_X;
        int ny = (indexY + velocityY[i] + DIMENSIONS_Y) % DIMENSIONS_Y;

        if (arr[nx][ny] == 'X') { aliveNeightbors++; }
    }

    return aliveNeightbors;
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


void WriteSecondToFirst(char (&first)[DIMENSIONS_X][DIMENSIONS_Y], const char (&second)[DIMENSIONS_X][DIMENSIONS_Y]) {
    for (int y = 0; y < DIMENSIONS_Y; y++) {
        for (int x = 0; x < DIMENSIONS_X; x++) {
            first[x][y] = second[x][y];
        }
    }
}


bool CompareArrays(const char (&first)[DIMENSIONS_X][DIMENSIONS_Y], const char (&second)[DIMENSIONS_X][DIMENSIONS_Y]) {
    for (int y = 0; y < DIMENSIONS_Y; y++) {
        for (int x = 0; x < DIMENSIONS_X; x++) {
            if (first[x][y] != second[x][y]) { return false; }
        }
    }

    return true;
}


int main() {
    char mainArr[DIMENSIONS_X][DIMENSIONS_Y];
    char prevArr[DIMENSIONS_X][DIMENSIONS_Y];

    std::ofstream outputFile (OUTPUT_FILE_NAME, std::ios::app);
    if (!outputFile) { std::cerr << "Error while opening output file!"; return -1; }
    auto Print = [&] (auto&&... args) { (std::cout << ... << args) << "\n"; (outputFile << ... << args) << "\n"; };

    ParseFile(mainArr);

    for (int i = 1; i < 100; i++) {
        WriteSecondToFirst(prevArr, mainArr);
        SimulateNextGen(mainArr);
        if (CompareArrays(mainArr, prevArr)) { Print("3. Pokolenie: ", i + 1); break; }
    }

    Print("Liczba żywych komórek: ", CountAlive(mainArr));
}
