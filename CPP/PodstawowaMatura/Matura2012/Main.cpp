#include <iostream>
#include <fstream>
#include <limits.h>

using namespace std;

bool NumIsEven(int num) { // func checks if given num is Even (parzyste)
    return num % 2 == 0;
}

int SumDigits(int num) {
    int sum = 0;

    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }

    return sum;
}

bool DigitsIncreasingOrder(int num) {
    int lastNum = num % 10;
    num /= 10;

    do {
        if (lastNum <= num % 10) { return false; }
        lastNum = num % 10;
        num /= 10;
    } 
    while (num > 0);

    return true;    
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

int main() { 
    // program entry point 
    fstream inputFile, outputFile;
    string tempWord;

    int tempNum;

    int lowest = INT_MAX, highest = INT_MIN;
    int lowestNum, highestNum;
    int counterEven = 0;

    inputFile.open("cyfry.txt", ios::in);
    outputFile.open("zadanie4.txt", ios::out);


    for (int i = 0; i < 1000; i++) {
        inputFile >> tempWord;
        tempNum = stringToInt(tempWord);

        if (NumIsEven(tempNum)) { 
            counterEven++;
        }

        if (SumDigits(tempNum) > highest) { highest = SumDigits(tempNum); highestNum = tempNum; }
        if (SumDigits(tempNum) < lowest) { lowest = SumDigits(tempNum); lowestNum = tempNum; }

    }

    cout << "Zadanie A. Ilość parzystych liczb: " << counterEven << endl << endl;
    outputFile << "Zadanie A. Ilość parzystych liczb: " << counterEven << endl << endl;

    cout << "Zadanie B. Największa suma cyfr w liczbie: " << highestNum << endl;
    cout << "Najmniejsza suma cyfr w liczbie: " << lowestNum << endl << endl;

    outputFile << "Zadanie B. Największa suma cyfr w liczbie: " << highestNum << endl;
    outputFile << "Najmniejsza suma cyfr w liczbie: " << lowestNum << endl << endl;

    inputFile.close();

    inputFile.open("cyfry.txt", ios::in);

    cout << "Zadanie C. Liczby w increasing order: " << endl;
    outputFile << "Zadanie C. Liczby w increasing order: " << endl;

    for (int i = 0; i < 1000; i++) {
        inputFile >> tempWord;
        tempNum = stringToInt(tempWord);

        if (DigitsIncreasingOrder(tempNum)) {
            cout << tempNum << endl;
            outputFile << tempNum << endl;
        }
    }

    outputFile.close();
}