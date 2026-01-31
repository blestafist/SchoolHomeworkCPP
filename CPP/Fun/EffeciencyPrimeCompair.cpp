#include <iostream>


bool IsPrimeV1(unsigned long long num) {
    if ( num < 2 ) { return false; }

    for (unsigned long long i = 2; i * i <= num; i++) {
        if (num % i == 0) { return false; }
    }

    return true;
}


bool IsPrimeV2(unsigned long long num) {
    if (num < 2) { return false; }
    if (num == 2 || num == 3) { return true; }
    if (num % 2 == 0 || num % 3 == 0) { return false; }

    for (unsigned long long i = 5; i * i <= num; i += 6) { 
        if (num % i == 0 || num % (i + 2) == 0) { return false; }
    }
    
    return true;
}
