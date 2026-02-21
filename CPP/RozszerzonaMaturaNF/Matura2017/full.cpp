#include <alloca.h>
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

    for (int y = 0; y < DIMENSIONS_Y; y++) {
        for (int x = 0; x < DIMENSIONS_X; x++) {
            if (inputFile >> current) {
                arr[x][y] = (unsigned char)current;
            }
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


int ContrastNeightboor(const unsigned char (&arr)[DIMENSIONS_X][DIMENSIONS_Y]) {
    // first define the conditions for checking
    int counter = 0;

    for (int x = 0; x < DIMENSIONS_X; x++) {
        for (int y = 0; y < DIMENSIONS_Y; y++) {
            bool isContrast = false;

            for (int i = 0; i < 4; i++) {
                int nx = x + vectorX[i];
                int ny = y + vectorY[i];

                if (nx >= 0 && nx < DIMENSIONS_X && ny >= 0 && ny < DIMENSIONS_Y) {
                    if (std::abs((int)arr[x][y] - (int)arr[nx][ny]) > 128) { isContrast = true; break; }
                }
            }

            if (isContrast) { counter++; }
        }
    }

    return counter;
}


void FindMinMax(unsigned char (&arr)[DIMENSIONS_X][DIMENSIONS_Y], unsigned char& min, unsigned char& max) {
    for (int y = 0; y < DIMENSIONS_Y; y++) {
        for (int x = 0; x < DIMENSIONS_X; x++) {
            if (arr[x][y] < min) { min = arr[x][y]; }
            if (arr[x][y] > max) { max = arr[x][y]; }
        }
    }
}


int NumLinesToRemove(unsigned char (&arr)[DIMENSIONS_X][DIMENSIONS_Y]) {
    int counter = 0; 

    for (int y = 0; y < DIMENSIONS_Y; y++) {
        for (int x = 0; x < DIMENSIONS_X; x++) {
            if (arr[x][y] != arr[DIMENSIONS_X - 1 - x][y]) { counter++; break; }
        }
    }

    return counter;
}


int SameBrightnessLongestOcc(unsigned char (&arr)[DIMENSIONS_X][DIMENSIONS_Y]) {
    int longest = 1, curr = 0;

    for (int x = 0; x < DIMENSIONS_X; x++) {
        curr = 1;

        for (int y = 1; y < DIMENSIONS_Y; y++) {
            if (arr[x][y] == arr[x][y - 1]) {
                curr++;
                if (curr > longest) { longest = curr; } 
            }

            else { curr = 1; }
        }
    }

    return longest;
}


int main() {
    std::ofstream outputFile (OUTPUT_FILE_NAME);
    if (!outputFile) { std::cerr << "Error while opening output file!"; return -1; }

    unsigned char mainArr[DIMENSIONS_X][DIMENSIONS_Y];
    unsigned char min = 255, max = 0; // opposite values
    
    auto Print = [&] (auto&&... args) { (std::cout << ... << args) << "\n"; (outputFile << ... << args) << "\n"; };

    ParseFile(mainArr); // opening an input file here
    FindMinMax(mainArr, min, max);
    
    Print("1. Najmniejszy: ", (int)min, "\nNajwiększy: ", (int)max);
    Print("\n2. Liczba wierszy: ", NumLinesToRemove(mainArr));
    Print("\n3. Kontrastujące piksele: ", ContrastNeightboor(mainArr));
    Print("\n4. Najdłuższa linia: ", SameBrightnessLongestOcc(mainArr));

    return 0;
}
