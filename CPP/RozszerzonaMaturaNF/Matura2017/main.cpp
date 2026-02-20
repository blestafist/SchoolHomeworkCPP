#include <iostream>
#include <fstream>


// ================================ CONFIGURATION ===================================

const std::string INPUT_FILE_NAME = "dane.txt"; // input file name here
const std::string OUTPUT_FILE_NAME = "wyniki6.txt"; // output file name here

const int DIMENSIONS_X = 320;
const int DIMENSIONS_Y = 200;

const int vectorX[] = { 0, 0, 1, -1 };
const int vectorY[] = { 1, -1, 0, 0 }; 

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
    int counter = 0;

    for (int x = 0; x < DIMENSIONS_X; x++) {
        for (int y = 0; y < DIMENSIONS_Y; y++) {
            bool isContrast = false;

            for (int i = 0; i < 4; i++) {
                int nx = x + vectorX[i];
                int ny = y + vectorY[i];

                if (nx >= 0 && nx < DIMENSIONS_X && ny >= 0 && ny < DIMENSIONS_Y) {
                    if (std::abs(arr[x][y] - arr[nx][ny]) > 128) { isContrast = true; break; }
                }
            }

            if (isContrast) { counter++; }
        }
    }

    return counter;
}

int main() {
    unsigned char mainArr[DIMENSIONS_X][DIMENSIONS_Y];
    ParseFile(mainArr);
    
    int counter
}