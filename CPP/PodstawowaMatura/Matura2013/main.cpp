#include <iostream>
#include <fstream>

using namespace std;


// ================ CONFIGURATION =================

const int FILE_LENTH = 1000;

const string INPUT_FILE_NAME = "napisy.txt";
const string OUTPUT_FILE_NAME = "zadanie4.txt";

// ================================================


bool IsCharsNumEven(string* str) {
    return (*str).size() % 2 == 0;
}

bool NumZeroesEqNumOnes(string* str) {
    int numZeroes = 0, numOnes = 0;

    for (int i = 0; i < (*str).size(); i++) {
        if ((*str)[i] == '0') { numZeroes++; }
        else { numOnes++; }
    }

    return numZeroes == numOnes;
}

bool ConsistrsOnlyFromZeroes(string* str) {
    for (int i = 0; i < (*str).size(); i++) {
        if ((*str)[i] == '1') { return false; }
    }
    
    return true;
}

bool ConsistrsOnlyFromOnes(string* str) {
    for (int i = 0; i < (*str).size(); i++) {
        if ((*str)[i] == '0') { return false; }
    }

    return true;
}

void AddNumberLengthToArray(string* str, int* arr) {
    int size = (*str).size();

    (*(arr + (size - 2)))++;
}



int main() {
    fstream inputFile, outputFile;

    int lengthesArray[14] {}; // min is 2, max is 16 (length)

    int EvenCharsQuantity = 0, NumZeroesEqNumOnesQuantity = 0, ConsistrsOnlyFromZeroesQuantity = 0, ConsistrsOnlyFromOnesQuantity = 0;
    string currentWord;



    inputFile.open(INPUT_FILE_NAME, ios::in);
    outputFile.open(OUTPUT_FILE_NAME, ios::out);

    for (int i = 0; i < FILE_LENTH; i++) {
        inputFile >> currentWord;

        if (IsCharsNumEven(&currentWord)) {
            EvenCharsQuantity++;

            if (NumZeroesEqNumOnes(&currentWord)) {
                NumZeroesEqNumOnesQuantity++;
            }
        }  

        if (ConsistrsOnlyFromOnes(&currentWord)) {
            ConsistrsOnlyFromOnesQuantity++;
        }

        else if (ConsistrsOnlyFromZeroes(&currentWord)) {
            ConsistrsOnlyFromZeroesQuantity++;
        }

        AddNumberLengthToArray(&currentWord, lengthesArray);
    }

    inputFile.close();

    cout << "1. Ilość napisów o parzystej długości: " << EvenCharsQuantity << endl << endl;
    outputFile << "1. Ilość napisów o parzystej długości: " << EvenCharsQuantity << endl << endl;

    cout << "2. Ilość napisów, zawierających tą samą liczbę zer i jedynek: " << NumZeroesEqNumOnesQuantity << endl << endl;
    outputFile << "2. Ilość napisów, zawierających tą samą liczbę zer i jedynek: " << NumZeroesEqNumOnesQuantity << endl << endl;

    cout << "3. Ilość napisów, zawierających same zera: " << ConsistrsOnlyFromZeroesQuantity << endl;
    cout << "Ilość napisów, zawierających same jedynki: " << ConsistrsOnlyFromOnesQuantity << endl << endl;

    outputFile << "3. Ilość napisów, zawierających same zera: " << ConsistrsOnlyFromZeroesQuantity << endl;
    outputFile << "Ilość napisów, zawierających same jedynki: " << ConsistrsOnlyFromOnesQuantity << endl << endl;

    cout << "4. Ilośc napisów o długości K: " << endl;
    outputFile << "4. Ilośc napisów o długości K: " << endl;


    for (int i = 0; i < 14; i++) {
        cout << "K = " << i + 2 << ": " << lengthesArray[i] << endl;
        outputFile << "K = " << i + 2 << ": " << lengthesArray[i] << endl;
    }

    outputFile.close();

}