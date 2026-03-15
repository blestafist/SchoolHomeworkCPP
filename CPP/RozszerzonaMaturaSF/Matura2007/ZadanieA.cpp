#include <iostream>
#include <fstream>


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
    return IsPrime(num) && SumDigitsPrimeBin(num) && SumDigitsPrime(num);
}


void WriteToFile(const std::string& fileName, int downRange, int upperRange) {
    std::ofstream outputFile(fileName);
    if (!outputFile) { std::cerr << "Error while opening output file: " << fileName; return;  }
    int counter = 0;

    for (int i = downRange; i <= upperRange; i++) {
        if (IsSuperB(i)) {
            counter++;
            outputFile << i << "\n";
        }
    }

    std::cout << "Dla przedziału <" << downRange << "; " << upperRange << "> " << counter << "\n";
    outputFile << "\n\nDla przedziału <" << downRange << "; " << upperRange << "> " << counter << "\n";
}


int main() { // entry point
    WriteToFile("1.txt", 2, 1000);
    WriteToFile("2.txt", 100, 10000);
    WriteToFile("3.txt", 1000, 100000);

    return 0;
}
