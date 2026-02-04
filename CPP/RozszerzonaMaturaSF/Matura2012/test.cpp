#include <iostream>
#include <fstream>
#include <iterator>

void EncryptWord(std::string& word, const std::string& keys) {
    for (char i = 0; i < word.size(); i++) {
        word[i] += keys[i % keys.size()];

        if (word[i] > 90) { word[i] -= 26; }
        std::cout << word[i] << " ";
    }
}

int main() {
    std::string word = "MARTA", key = "TOR";
    word[1] += 2; 
    std::cout << word << std::endl;
}
