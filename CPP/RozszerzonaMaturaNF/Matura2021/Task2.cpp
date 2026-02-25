#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

// =========================== CONFIGURATION ===========================

const std::string INPUT_FILE_NAME = "galerie_przyklad.txt";
const std::string OUTPUT_FILE_NAME = "wynik4_X.txt";

const int PAIR_COUNT = 0;

// =====================================================================

struct Pair {
    public:
        int x;
        int y;
};


int main() {
    std::ifstream inputFile (INPUT_FILE_NAME);
    if (!inputFile) { std::cerr << "Error while opening input file!"; return -1; }

    std::ofstream outputFile (OUTPUT_FILE_NAME);
    if (!outputFile) { std::cerr << "Error while opening output file!"; return -1; }

    std::string town;
    Pair tempPair, hashPair; // hashPair -- first → area | second → num of lcl
    std::unordered_map<std::string, Pair> map; // first → name of town, second is hash pair

    while (inputFile >> town >> town) {
        hashPair.x = 0; hashPair.y = 0;
        for (int i = 0; i < PAIR_COUNT; i++) {
            inputFile >> tempPair.x >> tempPair.y;
            if (tempPair.x == 0) { inputFile.ignore(10000, '\n'); break; }
            hashPair.x += tempPair.x * tempPair.y;
            hashPair.y++;
        }
        map[town] = hashPair;
    }

    return 0;
}
