#include <iostream>
#include <fstream>
using namespace std;

int const  ASCII_SUM = 220;

string const INPUT_FILE = "hasla.txt";

string const OUTPUT_FILE_A = "wynik4a.txt";
string const OUTPUT_FILE_B = "wynik4b.txt";
string const OUTPUT_FILE_C = "wynik4c.txt";

int IsEven(string tempPassword)
{
    return (tempPassword.size() % 2 == 0) ? true : false;
}

bool IsPalindrome(string tempPassword)
{
    for (int i = 0; i < tempPassword.size() / 2; i++)
    {
        if(tempPassword[i] != tempPassword[tempPassword.size() -1-i]) { return false; break; }
    }
    return true;
}

bool IsAsciiSum220(string tempPassword)
{
    for(int i = 0; i < tempPassword.size() - 2; i ++)
    {
        if(tempPassword[i] + tempPassword[i + 1] == 220) { return true; break; }
    }
    return false;
}
int main()
{
    ifstream inputFile (INPUT_FILE);    
    ofstream outputFileA (OUTPUT_FILE_A), outputFileB(OUTPUT_FILE_B), outputFileC(OUTPUT_FILE_C);

    string tempPassword;

    int counterOfEven = 0, counterOfNotEven;
    while (inputFile >> tempPassword)
    {
        (IsEven(tempPassword)) ? counterOfEven++ : counterOfNotEven++;

        if(IsPalindrome(tempPassword)) outputFileB << tempPassword << endl;
        if(IsAsciiSum220(tempPassword)) outputFileC << tempPassword << endl;
    }
    outputFileA << "hasła parzyste: " << counterOfEven << endl << "hasła nie parzyste: " << counterOfNotEven;



    inputFile.close();
    outputFileA.close(), outputFileB.close(), outputFileC.close();
}