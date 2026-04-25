#include <iostream>
#include <fstream>
#include <cstdlib>
#include <unordered_set>
#include <climits>

// =========================== CONFIGURATION ===========================

const std::string INPUT_FILE_NAME = "galerie.txt";
const std::string OUTPUT_FILE_NAME = "wynik4_3.txt";

const int PAIR_COUNT = 70;

// =====================================================================

int main() {
    std::ifstream inputFile (INPUT_FILE_NAME);
    if (!inputFile) { std::cerr << "Error while opening input file!"; std::exit(1); }

    std::ofstream outputFile (OUTPUT_FILE_NAME);
    if (!outputFile) { std::cerr << "Error while creating output file!"; std::exit(1); }

    auto Print = [&] (auto&&... args) { (std::cout << ... << args) << "\n"; (outputFile << ... << args) << "\n"; };

    std::string countryCode, town, minLocales, maxLocales;
    std::unordered_set<int> seenArea;
    int minLocalesCount = INT_MAX, maxLocalesCount = INT_MIN;

    while (inputFile >> countryCode >> town) {
        for (int i = 0; i < PAIR_COUNT; ++i) {
            int x, y, area;
            inputFile >> x >> y;
            area = x * y;

            if (area == 0) { continue; }

            if (!seenArea.count(area)) { seenArea.emplace(area); }
        }

        if (seenArea.size() > maxLocalesCount) { maxLocalesCount = seenArea.size(); maxLocales = town; }
        if (seenArea.size() < minLocalesCount) { minLocalesCount = seenArea.size(); minLocales = town; }

        seenArea.clear();
    }

    Print("Najmniejsza: ", minLocales, " → ", minLocalesCount);
    Print("Największa: ", maxLocales, " → ", maxLocalesCount);

    return 0;
}
