#include <iostream>

/*

1. Check if num is prime
2. Check if sum of digits is prime
3. Check if sum of bin is prime
4. Iterate the following range & count

*/

// ================================ CONFIGURATION ================================

const int DOWN_RANGE = 2;
const int UPPER_RANGE = 1000; // including upper num

// ===============================================================================

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



int main() {
    int counter = 0;

    for (int i = DOWN_RANGE; i <= UPPER_RANGE; i++) { // 4
        if (IsPrime(i) && SumDigitsPrime(i) && SumDigitsPrimeBin(i)) { counter++; }
    }

    std::cout << counter << std::endl;

    return 0;
}