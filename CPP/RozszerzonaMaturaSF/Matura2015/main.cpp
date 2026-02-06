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
    char occ0 = 0, occ1 = 0;

    for (char c : str) {
        if (c == '0') { occ0++; } else { occ1++; }
    }

    return occ0 > occ1;
}

bool TwoBlocksContainer(const std::string& str) {
    enum class State : char {
        Default,
        FoundFirstZero,
        FoundFirstOne
    };

    State state = State::Default;
    if (str[0] == '0') { state = State::FoundFirstZero; } else { return false; } 

    for (char c : str) {
        if (state == State::FoundFirstZero && c == '1') { state = State::FoundFirstOne; }
        else if (state == State::FoundFirstOne && c == '0') { return false; }
    }

    return state == State::FoundFirstOne;
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
    std::ofstream outputFile (OUTPUT_FILE);

    std::string tempWord;

    short more0Than1Counter = 0, containsTwoBlocksCounter = 0, maxOcc = 0;
    char currentOcc;

    std::vector<std::string> maxOccList;

    if (!inputFile.is_open()) { std::cout << "Error opening file!"; }

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

    std::cout << "\n\nNajdłuższy blok, złożony z samych zer: " << maxOcc << "\n";
    outputFile << "\n\nNajdłuższy blok, złożony z samych zer: " << maxOcc << "\n";

    for (std::string w : maxOccList) {
        std::cout << w << "\n";
        outputFile << w << "\n";
    }

    outputFile.close();

    return 0;
}