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

        void ComposeWord() {

        }   

    
    private:
        void ComposeLongestFromFront() {
            for (char i = 0; i < b.size(); i++) {
                if ()
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

    short palidromeCount = 0;


    while (inputFIle >> tempWord) {
        if (IsPalindrome(tempWord)) { palidromeCount++; }

        if (prevSecond) {  }
    }

    

    return 0;
}