#include <iostream>
#include <fstream>
#include <limits.h>

using namespace std;

bool NumIsEven(int num) { // func checks if given num is Even (parzyste)
    return num % 2 == 0;
}

int stringToInt(string str) { // func that converts string var to int
    int outputNum = 0;
    char tempChar;
    for (int i = 0; i < str.size(); i++) {
        outputNum *= 10;
        tempChar = str[i];
        outputNum += tempChar - 48;
    }

    return outputNum;
}

int main() { // program entry point 
    fstream inputFile, outputFile;
    string tempWord;

    int counterEven = 0;

    inputFile.open("cyfry.txt", ios::in);
    outputFile.open("zadanie4.txt", ios::out);


    for (int i = 0; i < 1000; i++) {
        inputFile >> tempWord;
        if (NumIsEven(stringToInt(tempWord))) { 
            counterEven++;
        }
    }

    cout << "1. Ilość parzystych liczb: " << counterEven << endl;
    outputFile << "1. Ilość parzystych liczb: " << counterEven << endl;

    inputFile.close();
    outputFile.close();
}