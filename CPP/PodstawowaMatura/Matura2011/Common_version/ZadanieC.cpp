#include <iostream>
#include <fstream>

using namespace std;

bool IsCorrectSum(string word) {
    for (int i = 0; i < word.size() - 1; i++) {
        if ((int)word[i] + (int)word[i + 1] == 220) { return true; }
    }
    return false;
}


int main() {
    fstream inputFile, outputFile;
    string tempWord;

    inputFile.open("hasla.txt", ios::in);
    outputFile.open("wynik4c.txt", ios::out);

    for (int i = 0; i < 200; i++) {
        inputFile >> tempWord;

        if (IsCorrectSum(tempWord)) {
            cout << tempWord << endl;
            outputFile << tempWord << endl;
        }
    }

    inputFile.close();
    outputFile.close();

    return 0;
}