#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>


/*

1. Count all words with 'A'
2. Check if first word contains second
3. Find if 2 words are anagrams 
    - Just sort both words && compare them

*/


// =========================== CONFIGURATION ===========================

const std::string INPUT_FILE = "slowa.txt";
const std::string OUTPUT_FILE = "wyniki6.txt";

// =====================================================================

bool IsPairAnagram(std::string firstWord, std::string secondWord) {
    std::sort(firstWord.begin(), firstWord.end());
    std::sort (secondWord.begin(), secondWord.end());

    return firstWord == secondWord;
}


int main() {
    std::ifstream inputFile (INPUT_FILE);
    std::ofstream outputFile (OUTPUT_FILE);

    std::string firstWord, secondWord;

    short endwithACounter = 0, firstContainsSecondCounter = 0, anagramsCounter = 0;

    std::vector<std::string> anagrams;

    if (!inputFile.is_open()) { std::cout << "Error while opening file!"; }

    while (inputFile >> firstWord >> secondWord) {
        if (firstWord[firstWord.size() - 1] == 'A') { endwithACounter++; }
        if (secondWord[secondWord.size() - 1] == 'A') { endwithACounter++; }

        if (secondWord.find(firstWord) != std::string::npos) { firstContainsSecondCounter++; }

        if (IsPairAnagram(firstWord, secondWord)) {
            anagramsCounter++;
            anagrams.push_back(firstWord); anagrams.push_back(secondWord);
        }
    }

    inputFile.close();


    std::cout << "Ilość słów kończących się na A: " << endwithACounter;

    std::cout << "\n\nIlość par, w których pierwsze słowo zawiera się w drugim: " << firstContainsSecondCounter << "\n\n"; 

    std::cout << "Ilość par-anagram: " << anagramsCounter << "\n";

    for (short i = 0; i < anagrams.size(); i += 2) {
        std::cout << anagrams[i] << " " << anagrams[i + 1] << "\n";
    }

    outputFile.close();
    return 0;
}