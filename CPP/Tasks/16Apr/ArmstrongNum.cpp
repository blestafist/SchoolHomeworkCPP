#include <iostream>

unsigned long long IntPower(int base, int exponent) {
    unsigned long long result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }

    return result;
}

int NumOfPlaces(unsigned long long num) {
    if (num == 0) { return 1; }
    int result = 0;

    while (num > 0) {
        result++;
        num /= 10;
    }

    return result;
}

bool IsArmstrong(unsigned long long num) {
    if (num == 0) { return true; }

    int numOfPlaces = NumOfPlaces(num);
    unsigned long long sum = 0, cp = num;

    while (cp > 0) {
        sum += IntPower((cp % 10), numOfPlaces);
        cp /= 10;

        if (sum > num) { return false; }
    }

    return sum == num;
}

int main() {
    for (unsigned long long i = 0; i < 100000000000ULL; i++) {
        if (IsArmstrong(i)) { std::cout << i << '\n'; }
    }

    return 0;
}
