#include <iostream>
#include <fstream>
#include <string>


// ============================== CONFIGURATION ==============================

const std::string INPUT_FILE = "dane.txt";
const std::string OUTPUT_FILE = "zad_5.txt";
const std::string OUTPUT_WORDS_FILE = "slowa.txt";

// ===========================================================================


struct TwoStr {
    public:
        std::string a; // naming a & b bcs in task
        std::string b;

        std::string composedWordFront = b + a, composedWordBack = a + b; // front / back of origin (A)

        bool AContainsB() {
            return a.find(b) != std::string::npos;
        }

        bool AContainsBWithout() {
            if (b.size() > a.size()) { return false; }
            size_t maxLength = a.size() - b.size() + 1;

            for (size_t i = 0; i < maxLength; i++) {
                for (size_t j = 0; j < b.size(); j++) {
                    if (a[j + i] != b[j]) { break; }
                    if (j == b.size() - 1) { return true; }
                }
            }

            return false;
        }

        void ComposeWord() {

        }


    private:
        void ComposeLongestFromFront() {
            for (char i = 0; i < b.size(); i++) {
            }
        }
};


bool IsPalindrome(const std::string& word) {
    for (char i = 0; i < word.size() / 2; i++) {
        if (word[i] != word[word.size() - 1 - i]) { return false; }
    }

    return true;
}



int main() {
    std::ifstream inputFIle (INPUT_FILE);
    std::ofstream outputFileAnswers(OUTPUT_FILE), outputFileWords(OUTPUT_WORDS_FILE);

    std::string tempWord;
    bool prevSecond = true;

    short palindromeCount = 0;


    /* while (inputFIle >> tempWord) {
        if (IsPalindrome(tempWord)) { palidromeCount++; }

        if (prevSecond) {  }
    } */

    std::string a = "001101",
    b = "110";

    std::cout << AContainsBExt(a, b);



    return 0;
}
