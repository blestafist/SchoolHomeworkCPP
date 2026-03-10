#include <iostream>
#include <fstream>

// =========================== CONFIGURATION ===========================

const std::string OUTPUT_FILE_NAME = "wyniki.txt";

const int DOWN_RANGE = 100;
const int UPPER_RANGE = 10000;

// =====================================================================


bool IsPrime(int num) { // 1
    if (num == 2 || num == 3) { return true; }
    if (num % 2 == 0 || num % 3 == 0 || num < 2) { return false; }

    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) { return false; }
    }

    return true;
}


bool SumDigitsPrime(int num) {
    int result = 0;
    while (num > 0) { result += num % 10; num /= 10; }

    return IsPrime(result);
}


bool SumDigitsPrimeBin(int num) {
    int result = 0;
    while (num > 0) { result += num % 2; num /= 2; }

    return IsPrime(result);
}

bool IsSuperB(int num) {
    return IsPrime(num) && SumDigitsPrimeBin(num);
}


int main() { // entry point
    std::ofstream outputFile (OUTPUT_FILE_NAME);
    if (!outputFile) { std::cerr << "Error while opening output file!"; return -1; }

    int sum = 0;
    int sumDigitsPrimeCounter = 0;

    auto Print = [&] (auto&&... args) { (std::cout << ... << args) << "\n"; (outputFile << ... << args) << "\n"; };

    for (int i = DOWN_RANGE; i <= UPPER_RANGE; i++) {
        if (SumDigitsPrime(i)) {
            sumDigitsPrimeCounter++;
            if (IsSuperB(i)) { sum += i; }
        }
    }

    Print("Ilość liczb, których suma cyfr jest liczbą pierwszą: ", sumDigitsPrimeCounter);
    
    if (IsPrime(sum)) {
        Print("Tak, suma wszystkich liczb B pierwszych jest pierwsza");
    }
    else { Print("Nie, suma wszystkich liczb B pierwszych nie jest pierwsza"); }

    return 0;
}
