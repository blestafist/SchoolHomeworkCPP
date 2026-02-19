#include <iostream>
#include <fstream>
#include <vector>

// =========================== CONFIGURATION ===========================

const std::string INPUT_FILE = "slowa.txt";
const std::string OUTPUT_FILE = "wynik4.txt";

// =====================================================================

bool More0Than1(const std::string& str) {
    char occ = 0;

    for (char c : str) {
        if (c == '0') { occ++; } else { occ--; }
    }

    return occ > 0;
}

bool TwoBlocksContainer(const std::string& str) {
    if (str[0] != '0' || str[str.size() - 1] != '1') { return false; }
    bool wasChange = false;

    for (unsigned char i = 0; i < str.size() - 1; i++) {
        if (str[i] != str[i + 1]) { 
            if (wasChange) { return false; }
            wasChange = true;
        }
    }

    return wasChange;
}

char CountLongest0Occ(const std::string& str) {
    char occ = 0, maxOcc = 0;
    for (char c : str) {
        if (c == '0') { occ++; if (occ > maxOcc) { maxOcc = occ; } } else { occ = 0; }
    }

    return maxOcc;
}


int main() {
    std::ifstream inputFile (INPUT_FILE);
    if (!inputFile) { std::cerr << "Error while opening input file!"; return -1; }

    std::ofstream outputFile (OUTPUT_FILE);
    if (!outputFile) { std::cerr << "Error while opening output file!"; return -1; }

    std::string tempWord;
    auto Print = [&] (auto&&... args) { (std::cout << ... << args) << "\n"; (outputFile << ... << args) << "\n"; };

    short more0Than1Counter = 0, containsTwoBlocksCounter = 0;
    unsigned char currentOcc, maxOcc = 0;

    std::vector<std::string> maxOccList;

    while (inputFile >> tempWord) {
        if (More0Than1(tempWord)) { more0Than1Counter++; }
        if (TwoBlocksContainer(tempWord)) { containsTwoBlocksCounter++; }

        currentOcc = CountLongest0Occ(tempWord);
        if (maxOcc == currentOcc) { maxOccList.push_back(tempWord); }
        else if (maxOcc < currentOcc) { maxOcc = currentOcc; maxOccList.clear(); maxOccList.push_back(tempWord); }
    }

    Print("Liczba słow, w których liczba zer jest większa od liczby jedynek: ", more0Than1Counter, "\n");
    Print("Liczba słow, składających się z 2 bloków zer i jedynek: ", containsTwoBlocksCounter, "\n");
    Print("Najdłuższy blok, złożony z samych zer: ", (short)maxOcc);

    for (std::string w : maxOccList) {
        Print(w);
    }

    return 0;
}
