#include <algorithm>
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>

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
    auto rev = [] (std::string s) -> std::string { std::reverse(s.begin(), s.end());  return s; };

    std::unordered_map<std::string, int> words, mirrorWords;
    std::vector<std::string> seq;


    while (inputFileNew >> tempWord) {
        seq.push_back(tempWord);
        words[tempWord] = 0;
        mirrorWords[rev(tempWord)] = 0;
    }

    inputFileNew.close(); // end of work with inputFileNew

    // now working with words
    while (inputFileWords >> tempWord) {
        if (words.count(tempWord) != 0) {
            words[tempWord]++;
        }

        if (mirrorWords.count(tempWord)) {
            mirrorWords[tempWord]++;
        }
    }

    // now displaying answers
    for (const std::string& str : seq) {
        std::cout << str << " → " << words[str] << " → " << mirrorWords[rev(str)] << "\n";
        outputFile << str << " → " << words[str] << " → " << mirrorWords[rev(str)] << "\n";
    }

    return 0;
}
