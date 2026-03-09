#include <iostream>
#include <fstream>
#include <algorithm>

const std::string INPUT_FILE_NAME = "dane.txt";
const std::string OUTPUT_FILE_NAME = "wynik.txt";

int main() {
    std::ifstream inputFile (INPUT_FILE_NAME);
    if (!inputFile) { std::cerr << "Error while opening input file!"; return -1; }

    std::ofstream outputFile (OUTPUT_FILE_NAME);
    if (!outputFile) { std::cerr << "Error while opening output file!"; return -1; }

    std::string tab[10000], maxWord;
    int wordCount = 0;

    while (inputFile >> tab[wordCount] && wordCount < 10000) { wordCount++; }

    std::sort(tab, tab + wordCount);

    int duplicateCount = 0, currentCount = 1, maxCount = 0;

    for (int i = 0; i < wordCount - 1; i++) {
        if (tab[i] == tab[i + 1]) {
            currentCount++;
            if (currentCount > maxCount) {
                maxCount = currentCount;
                maxWord = tab[i];
            }
        }

        else {
            if (currentCount > 1) { duplicateCount++; }
            currentCount = 1;
        }
    }

    auto Print = [&] (auto&&... args) { (std::cout << ... << args) << "\n"; (outputFile << ... << args) << "\n"; };

    Print("A. Słów, występujących więcej niż 1 raz: ", duplicateCount);
    Print("B. Słowo o największej liczbie wystąpeń: ", maxWord);
    Print("C. Występuje razy: ", maxCount);

    return 0;
}
