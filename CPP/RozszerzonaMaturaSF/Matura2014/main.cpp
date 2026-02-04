#include <iostream>
#include <fstream>
#include <vector>
#include <map>


// =========================== CONFIGURATION ===========================

const std::string INPUT_FILE = "NAPIS.TXT";
const std::string OUTPUT_FILE = "ZADANIE5.TXT";

// =====================================================================

bool IsPrime(unsigned short num) {
    if (num < 2) { return false; }
    if (num == 2 || num == 3) { return true; }
    if (num % 2 == 0 || num % 3 == 0) { return false; }

    for (unsigned short i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) { return false; }
    }

    return true;
}

bool SumCodesPrime(const std::string& str) {
    int result = 0;
    for (char c : str) { result += c; }
    return IsPrime(result);
}

bool IncreasingNum(const std::string& str) {
    for (char i = 0; i < str.size() - 1; i++) {
        if (str[i] >= str[i + 1]) { return false; }
    }
    return true;
}

int main() {
    std::ifstream inputFile (INPUT_FILE);
    std::ofstream outputFile (OUTPUT_FILE);

    std::string tempWord;
    std::vector<std::string> incerasingWords;
    std::map<std::string, char> ctr;

    short primeWordsCounter;

    while (inputFile >> tempWord) {
        if (SumCodesPrime(tempWord)) { primeWordsCounter++; }

        if(IncreasingNum(tempWord)) { incerasingWords.push_back(tempWord); }

        ctr[tempWord]++;
    }

    std::cout << "Ilość napisów pierwszych: " << primeWordsCounter;
    outputFile << "Ilość napisów pierwszych: " << primeWordsCounter;

    std::cout << "\n\nNapisy rosnące: \n";
    outputFile << "\n\nNapisy rosnące: \n";

    for (std::string word : incerasingWords) { std::cout << word << "\n"; outputFile << word << "\n"; }

    std::cout << "\nNapisy, które występują więcej niż 1 raz: \n";
    outputFile << "\nNapisy, które występują więcej niż 1 raz: \n";

    for (const auto& [str, count] : ctr) {
        if (count > 1) { std::cout << str << "\n"; outputFile << str << "\n"; }
    }

    return 0;
}