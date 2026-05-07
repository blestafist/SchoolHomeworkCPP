#include <iostream>
#include <fstream>
#include <limits.h>

// =========================== CONFIGURATION ===========================

const std::string INPUT_FILE_NAME = "galerie.txt";
const std::string OUTPUT_FILE_NAME = "wynik4_2.txt";

const int PAIR_COUNT = 70;

// =====================================================================


int main() {
    std::ifstream inputFile (INPUT_FILE_NAME);
    if (!inputFile) { std::cerr << "Error while opening input file!"; return -1; }

    std::ofstream outputFile (OUTPUT_FILE_NAME);
    if (!outputFile) { std::cerr << "Error while opening output file!"; return -1; }

    auto Print = [&] (auto&&... args) { (std::cout << ... << args) << "\n"; (outputFile << ... << args) << "\n"; };

    std::string countryCode, town, maxAreaLabel, minAreaLabel;
    int maxArea = 0, minArea = INT_MAX;

    while (inputFile >> countryCode >> town) {
        int totalArea = 0, totalCount = 0;
        for (int i = 0; i < PAIR_COUNT; i++) {
            int x, y;
            inputFile >> x >> y;

            if (x > 0 && y > 0) {
                totalArea += x * y;
                ++totalCount;
            }
        }

        Print(town, ' ', totalArea, ' ', totalCount);

        if (maxArea < totalArea) { maxArea = totalArea; maxAreaLabel = town; }
        if (minArea > totalArea) { minArea = totalArea; minAreaLabel = town; }
    }

    Print("\nNajwiększe: ", maxAreaLabel, ' ', maxArea);
    Print("Najmniejsze: ", minAreaLabel, ' ', minArea);

    return 0;
}
