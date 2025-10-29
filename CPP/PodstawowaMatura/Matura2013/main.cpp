#include <iostream>
#include <fstream>

using namespace std;


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

void 

int main() {

}