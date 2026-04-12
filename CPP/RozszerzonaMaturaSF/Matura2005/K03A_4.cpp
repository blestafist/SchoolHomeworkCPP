#include <iostream>
#include <fstream>
#include <vector>

// =========================== CONFIGURATION ===========================

const std::string INPUT_FILE_NAME = "energia.txt";
const std::string OUTPUT_FILE_NAME = "wyniki04.txt";

// =====================================================================

int main() {
    std::ifstream inputFile (INPUT_FILE_NAME);
    if (!inputFile) { std::cerr << "Error while opening input file!"; return -1; }

    std::ofstream outputFile (OUTPUT_FILE_NAME);

    int tempInt;

    std::vector<int> temp;

    while (inputFile >> tempInt) {
        temp.push_back(tempInt);
    }

    int bestStartIndex = 0,
    bestEndIndex = 0,
    currStartIndex = 0,
    localEnergy = temp[0],
    maxEnergy = temp[0];

    for (size_t i = 1; i < temp.size(); i++) {
        if (localEnergy + temp[i] < temp[i]) {
            localEnergy = temp[i];
            currStartIndex = i;
        }

        else { localEnergy += temp[i]; }

        if (localEnergy >= maxEnergy) {
            maxEnergy = localEnergy;
            bestStartIndex = currStartIndex;
            bestEndIndex = i;
        }
    }

    auto Print = [&] (auto&&... args) { (std::cout << ... << args) << "\n"; (outputFile << ... << args) << "\n"; };

    Print("Maksymalny przyrost energii: ", maxEnergy);
    Print("Odnotowano w przedziale: ", bestStartIndex + 1, " → ", bestEndIndex + 1);

    return 0;
}
