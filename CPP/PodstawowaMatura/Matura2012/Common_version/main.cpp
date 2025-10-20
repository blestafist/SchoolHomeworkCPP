#include <iostream>
#include <fstream>

using namespace std;

bool NumIsEven(int num) { // func checks if given num is Even (parzyste)
    return num % 2 == 0;
}


int main() { // program entry point 
    fstream inputFile, outputFile;
    string tempWord;

    int counterEven = 0;

    inputFile.open("cyfry.txt", ios::in);
    outputFile.open("zadanie4.txt", ios::out);


    for (int i = 0; i < 1000; i++) {
        inputFile >> tempWord;
        if (NumIsEven(tempWord)) { 
            counterEven++;
        }
    }

    cout << "1. Ilość parzystych liczb: " << counterEven << endl;
    outputFile << "1. Ilość parzystych liczb: " << counterEven << endl;

    inputFile.close();
    outputFile.close();
}