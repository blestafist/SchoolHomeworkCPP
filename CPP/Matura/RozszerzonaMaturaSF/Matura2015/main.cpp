#include <iostream>
#include <fstream>
#include <string>
#include <vector>

/* 

1. Check where number of 0 higher than number of 1
2. Check if the number contain two blocks
    - Just count occurencies of "01" or "10"

3. Iterate and find words with longest 0-block, save them to vector
    - If found a longer block, clear the vector && write a word to it

*/

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

    short more0Than1Counter = 0, 
    containsTwoBlocksCounter = 0;

    unsigned char currentOcc, maxOcc = 0;

    std::vector<std::string> maxOccList;

    while (inputFile >> tempWord) {
        if (More0Than1(tempWord)) { more0Than1Counter++; }
        if (TwoBlocksContainer(tempWord)) { containsTwoBlocksCounter++; }

        currentOcc = CountLongest0Occ(tempWord);
        if (maxOcc == currentOcc) { maxOccList.push_back(tempWord); }
        else if (maxOcc < currentOcc) { maxOcc = currentOcc; maxOccList.clear(); maxOccList.push_back(tempWord); }
    }

    inputFile.close();

    std::cout << "Liczba słow, w których liczba zer jest większa od liczby jedynek: " << more0Than1Counter;
    outputFile << "Liczba słow, w których liczba zer jest większa od liczby jedynek: " << more0Than1Counter;

    std::cout << "\n\nLiczba słow, składających się z 2 bloków zer i jedynek: " << containsTwoBlocksCounter;
    outputFile << "\n\nLiczba słow, składających się z 2 bloków zer i jedynek: " << containsTwoBlocksCounter;

    std::cout << "\n\nNajdłuższy blok, złożony z samych zer: " << (short)maxOcc << "\n";
    outputFile << "\n\nNajdłuższy blok, złożony z samych zer: " << (short)maxOcc << "\n";

    for (std::string w : maxOccList) {
        std::cout << w << "\n";
        outputFile << w << "\n";
    }

    outputFile.close();

    return 0;
}
