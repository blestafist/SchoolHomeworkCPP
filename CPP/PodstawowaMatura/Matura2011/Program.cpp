#include <iostream>
#include <fstream>

using namespace std;

// =========== CONFIGURATION ================

const int ASCII_SUM = 220;  // sum of ascii code to check

const string INPUT_FILE_NAME = "hasla.txt"; 
const short NUM_OF_STRINGS_IN_FILE = 200;

const string OUTPUT_FILE_NAME_A = "wynik4a.txt";
const string OUTPUT_FILE_NAME_B = "wynik4b.txt";
const string OUTPUT_FILE_NAME_C = "wynik4c.txt";

    

bool NumCharsEven(string* inputWord) {
    return (*inputWord).size() % 2 == 0;
}

bool IsPalindrome(string* word) {
    for (int i = 0; i < (*word).size() / 2; i++) {
        if ((*word)[i] != (*word)[(*word).size() - i - 1]) { return false; }
    }
    return true;
}

bool IsCorrectSum(string* word) {
    for (int i = 0; i < (*word).size() - 1; i++) {
        if ((int)(*word)[i] + (int)(*word)[i + 1] == ASCII_SUM) { return true; }
    }
    return false;
}


int main() { // program entry point
    fstream inputFile; // declaring input file
    fstream outputFileTaskA, outputFileTaskB, outputFileTaskC;

    string currentWord;
    int evenWordsCounter = 0;


    inputFile.open(INPUT_FILE_NAME, ios::in);

    outputFileTaskA.open(OUTPUT_FILE_NAME_A, ios::out);
    outputFileTaskB.open(OUTPUT_FILE_NAME_B, ios::out);
    outputFileTaskC.open(OUTPUT_FILE_NAME_C, ios::out);


    for (int i = 0; i < NUM_OF_STRINGS_IN_FILE; i++) {
        inputFile >> currentWord;

        if (NumCharsEven(&currentWord)) { 
            evenWordsCounter++;
        }

        if (IsPalindrome(&currentWord)) {
            cout << "Zadanie B: " << currentWord << endl;
            outputFileTaskB << currentWord << endl;
        }

        if (IsCorrectSum(&currentWord)) {
            cout << "Zadanie C: " << currentWord << endl;
            outputFileTaskC << currentWord << endl;
        }
    }

    cout << "W pliku znajduje się " << evenWordsCounter << " parzystych hasel" << endl;
    outputFileTaskA << "W pliku znajduje się " << evenWordsCounter << " parzystych hasel" << endl;
    
    cout << "W pliku znajduje się " << NUM_OF_STRINGS_IN_FILE - evenWordsCounter << " nieparzystych hasel" << endl;
    outputFileTaskA << "W pliku znajduje się " << NUM_OF_STRINGS_IN_FILE - evenWordsCounter << " nieparzystych hasel" << endl;


    inputFile.close();
    outputFileTaskA.close();
    outputFileTaskB.close();
    outputFileTaskC.close();

}