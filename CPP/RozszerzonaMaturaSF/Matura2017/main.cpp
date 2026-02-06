#include <cstddef>
#include <iostream>
#include <fstream>


/*

1. Check if contains two same substr (check if [0] == [0 + size / 2])
2  Check if first & last are 1, and if [1] || [2] == '1' return false
3. Convert into decimal, compare to 65535 (short max)
4. Find highest then print it in decimal & binary

*/


// =========================== CONFIGURATION ===========================

const std::string INPUT_FILE = "binarne.txt";
const std::string OUTPUT_FILE = "zadanie4.txt";

// =====================================================================


bool ContainsTwoIdSubstr(const std::string& str) {
    size_t half = str.size() / 2;

    for (size_t i = 0; i < half; i++) {
        if (str[i] != str[i + half]) { return false; }
    }

    return true;
}

bool IsLower9(const std::string str) {
    for (char i = 0 ; i < str.size(); i += 4) {
        if (str[i] == '1') { 
            if (str[i + 1] == '1' || str[i + 2] == '1') { return false; }
        }
    }

    return true;
} 


int ConvertToDecimal(const std::string& str) {
    int result = 0;

    for (char c : str) {
        result = (result << 1) + (c - '0');
    }

    return result;
}


int main() {
    std::ifstream inputFile (INPUT_FILE);
    std::ofstream outputFile (OUTPUT_FILE);

    std::string binary, highestBinary, twoSubstr;
    
    short longestSubstr = 0, minimalInorrectLength = 30000;
    int decimal, highestD = 0, substrCounter = 0, incorrectCounter = 0;

    while (inputFile >> binary) {
        decimal = ConvertToDecimal(binary);

        if (ContainsTwoIdSubstr(binary)) {
            substrCounter++;
            if (longestSubstr < binary.length()) { longestSubstr = binary.length(); twoSubstr = binary; }
        }

        if (!IsLower9(binary)) { 
            incorrectCounter++;
            if (binary.length() < minimalInorrectLength) { 
                minimalInorrectLength = binary.length(); 
            }
        }

        if (decimal <= 65535) {
            if (decimal > highestD) { highestD = decimal; highestBinary = binary; }
        }
    }

    std::cout << "A. Ilość napisów dwucyklicznych: " << substrCounter << ". Najdłuższy: " << twoSubstr << ". Jego długość: " << twoSubstr.length();

    std::cout << "\n\nB. Liczba niepoprawnych napisów: " << incorrectCounter << ". Najkrótszy: " << minimalInorrectLength;

    std::cout << "\n\nC. Największa poniżej 65535: " << highestD << ". W binarnym: " << highestBinary << "\n";
}