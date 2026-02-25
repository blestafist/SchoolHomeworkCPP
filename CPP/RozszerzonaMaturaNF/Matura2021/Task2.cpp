#include <iostream>
#include <fstream>

// =========================== CONFIGURATION ===========================

const std::string INPUT_FILE_NAME = "galerie_przyklad.txt";
const std::string OUTPUT_FILE_NAME = "wynik4_2.txt";

const int PAIR_COUNT = 70;

// =====================================================================


int main() {
    std::ifstream inputFile (INPUT_FILE_NAME);
    if (!inputFile) { std::cerr << "Error while opening input file!"; return -1; }

    std::ofstream outputFile (OUTPUT_FILE_NAME);
    if (!outputFile) { std::cerr << "Error while opening output file!"; return -1; }

    std::string countryCode, town;

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

        std::cout << town << ' ' << totalArea << ' ' << totalCount << '\n';
        outputFile << town << ' ' << totalArea << ' ' << totalCount << '\n';
    }

    return 0;
}
