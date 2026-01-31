#include <fstream>
#include <iostream>

/*

! 1st

1. IsPrime interface realisation
2. Check if sum of digits is prime
3. Count and display the answer

! 2nd

1. Count the sum of nums in 2.txt (<100, 10000>)
2. Check if prime

*/

bool IsPrime(unsigned short num) { // most efficient IsPrime (3-5x faster than Darius April variant)
    if (num < 2) { return false; }
    if (num == 2 || num == 3) { return true; }
    if (num % 2 == 0 || num % 3 == 0) { return false; }

    for (unsigned short i = 5; i * i <= num; i += 6) { 
        if (num % i == 0 || num % (i + 2) == 0) { return false; }
    }
    
    return true;
}

bool SumDigitsPrime(unsigned short num) { // 2
    short result = 0;

    while (num > 0) {
        result += num % 10;
        num /= 10;
    }

    return IsPrime(result);
}

int main() {
    unsigned short counter = 0, tempNum;
    long sumResult = 0;

    for (unsigned short i = 100; i < 10000; i++) {
        if (SumDigitsPrime(i)) { counter++; }
    }

    std::ifstream inputFile ("2.txt");

    while (inputFile >> tempNum) {
        tempNum += sumResult;
    }

    std::cout << counter << "\n" << IsPrime(sumResult) << "\n";
}