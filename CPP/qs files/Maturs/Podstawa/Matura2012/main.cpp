#include <iostream>
#include <fstream>

using namespace std;

const string INPUT_FILE = "cyfry.txt";
const string OUTPUT_FILE = "zadanie4.txt";

bool IsEven(int tempInt)
{
    return tempInt % 2 == 0 ? true : false;
}

int main()
{
    ifstream inputFile (INPUT_FILE);
    ofstream outputFile (OUTPUT_FILE);

    if(!inputFile.is_open()) cout << "error open file";

    int tempInt, counter = 0, minNum;

    while(inputFile >> tempInt)
    {
        if(IsEven(tempInt)) counter++;
    }

    cout << "zadanieA" << endl << counter << endl;
    outputFile << "zadanieA" << endl << counter << endl;

    inputFile.close();
    inputFile.open(INPUT_FILE);

    inputFile >> tempInt;
    minNum = tempInt;
    
    cout << minNum << endl;
    while(inputFile >> tempInt)
    {
        if(minNum < tempInt)
            minNum = tempInt;
    }
    
    inputFile.close();
    outputFile.close();
}