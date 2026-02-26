#include <iostream>
#include <fstream>
#include <unordered_map>

// =========================== CONFIGURATION ===========================

const std::string INPUT_FILE_NAME = "dane.txt";
const std::string OUTPUT_FILE_NAME = "wynik.txt";

// =====================================================================

int main() {
    std::ifstream inputFile (INPUT_FILE_NAME);
    if (!inputFile) { std::cerr << "Error while opening input file!"; return -1;}

    std::ofstream outputFile (OUTPUT_FILE_NAME);
    if (!outputFile) { std::cerr << "Error while opening output file!"; return -1; }

    std::string tempWord;
    std::unordered_map<std::string, int> wordsCounter; // word : count

    auto Print = [&] (auto&&... args) { (std::cout << ... << args) << "\n"; (outputFile << ... << args) << "\n"; };

    while (inputFile >> tempWord) {
        wordsCounter[tempWord]++;
    }


    int maxOcc = 0, moreThanOneOccCount = 0;
    std::string maxOccWord;

    for (const auto& [word, count] : wordsCounter) {
        if (count > 1) {
            moreThanOneOccCount++;
            if (count > maxOcc) { maxOcc = count; maxOccWord = word; }
        }
    }

    Print("A. Słów, występujących więcej niż 1 raz: ", moreThanOneOccCount);
    Print("B. Słowo o największej liczbie wystąpeń: ", maxOccWord);
    Print("C. Występuje razy: ", maxOcc);

    return 0;
}
