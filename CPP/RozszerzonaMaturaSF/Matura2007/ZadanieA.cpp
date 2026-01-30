#include <iostream>
#include <fstream>

/*

1. Check if num is prime
2. Check if sum of digits is prime
3. Check if sum of bin is prime
4. Iterate the following range & count
5. Write to file

*/

bool IsPrime(int num) { // 1
    if (num == 2) { return true; }
    if (num < 2 || num % 2 == 0) { return false; }

    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) { return false; }
    }

    return true;
}


bool SumDigitsPrime(int num) { // 2
    short result = 0;

    while (num > 0) {
        result += num % 10;
        num /= 10;
    }

    return IsPrime(result);
}


bool SumDigitsPrimeBin(int num) { // 3
    short result = 0;

    while (num > 0) {
        result += num % 2;
        num /= 2;
    }

    return IsPrime(result);
}


void WriteToFile(const std::string& fileName, int downRange, int upperRange) {
    std::ofstream output(fileName);
    int counter = 0;

    for (int i = downRange; i <= upperRange; i++) {
        if (IsPrime(i) && (SumDigitsPrime(i) && SumDigitsPrimeBin(i))) {
            counter++;
            output << i << "\n";
        }
    }

    std::cout << counter << "\n";
    output.close();
}


int main() { // entry point
    WriteToFile("1.txt", 2, 1000);
    WriteToFile("2.txt", 100, 10000);
    WriteToFile("3.txt", 1000, 100000);

    return 0;
}