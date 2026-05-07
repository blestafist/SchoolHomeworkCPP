#include <iostream>
#include <fstream>

using namespace std;

bool IsPalindrome(string word) {
    for (int i = 0; i < word.size() / 2; i++) {
        if (word[i] != word[word.size() - i - 1]) { return false; }
    }
    return true;
}


int main() {
    fstream inputFile, outputFile;
    string tempWord;

    inputFile.open("hasla.txt", ios::in);
    outputFile.open("wynik4b.txt", ios::out);

    for (int i = 0; i < 200; i++) {
        inputFile >> tempWord;

        if (IsPalindrome(tempWord)) {
            cout << tempWord << endl;
            outputFile << tempWord << endl;
        }
    }

    inputFile.close();
    outputFile.close();

    return 0;
}