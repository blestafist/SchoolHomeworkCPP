#include <algorithm>
#include <iostream>
#include <fstream>
#include <unordered_map>

// ======================== CONFIGURATION ========================

const std::string INPUT_FILE_NAME = "slowa.txt";
const std::string NEW_INPUT_FILE_NAME = "nowe.txt";

const std::string OUTPUT_FILE_NAME = "wynik5.txt";

// ===============================================================

int main() {
    std::ifstream inputFileWords (INPUT_FILE_NAME), inputFileNew (NEW_INPUT_FILE_NAME);
    if (!inputFileWords || !inputFileNew) { std::cerr << "Error while opening input files!"; return -1; }

    std::ofstream outputFile (OUTPUT_FILE_NAME, std::ios::app);
    if (!outputFile) { std::cerr << "Error while opening output file!"; return -1; }

    std::string tempWord;

    std::unordered_map<std::string, int> words;
    std::unordered_map<std::string, int> mirrorWords;


    while (inputFileNew >> tempWord) {
        words[tempWord] = 0;

        std::reverse(tempWord.begin(), tempWord.end());

        mirrorWords[tempWord] = 0;
    }

    inputFileNew.close(); // end of work with inputFileNew

    // now working with words
    while (inputFileWords >> tempWord) {
        if (words.count(tempWord) != 0) {
            words[tempWord]++;
        }

        if (mirrorWords.count(tempWord) != 0) {
            mirrorWords[tempWord]++;
        }
    }

    for (int i = 0; i < words.size(); i++) {
        std::cout << mirrorWords.
    }
}