#include <iostream>
#include <fstream>

using namespace std;

bool NumCharsEven(string inputWord) {
    return inputWord.size() % 2 == 0;
}

int main() {
    fstream inputFile, outputFile;
    string tempWord;

    inputFile.open("hasla.txt", ios::in);

    int counter = 0;

    for (int i = 0; i < 200; i++) {
        inputFile >> tempWord;

        if (NumCharsEven(tempWord)) { counter++; }
    }


    inputFile.close();
    outputFile.open("wynik4a.txt", ios::out);

    cout << "Ilość haseł z parzystą ilośćią znaków: " << counter << endl;
    outputFile << "Ilość haseł z parzystą ilośćią znaków: " << counter << endl;

    cout << "Ilość haseł z nieparzystą ilośćią znaków: " << 200 - counter << endl;
    outputFile << "Ilość haseł z nieparzystą ilośćią znaków: " << 200 - counter << endl;

    outputFile.close();

    return 0;
}