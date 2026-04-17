#include <iostream>

int powers[10] {};

int PowerInt(int base, int exp) {
    int result = 1;

    for (int i = 0; i < exp; i++) {
        result *= base;
    }

    return result;
}

bool IsMuchausen(unsigned long long num) {
    if (num == 0) { return false; }
    unsigned long long sum = 0, cp = num;

    while (cp > 0) {
        sum += powers[cp % 10];
        cp /= 10;
    }

    return sum == num;
}

int main() {

    for (int i = 0; i < 10; i++) {
        powers[i] = PowerInt(i, i);
        std::cout << i << ' ' << powers[i] << '\n';
    }

    powers[0] = 0; // comment / uncomment this line to follow / not follow the OEIS rules

    for (unsigned long long i = 0; i < 500000000ULL; i++) {
        if (IsMuchausen(i)) { std::cout << i << "\n"; }
    }

    return 0;
}
