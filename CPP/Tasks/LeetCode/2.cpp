#include <iostream>
using namespace std;

int titleToNumber(string columnTitle) {
    int result = 0;

    for (char c : columnTitle) {
        result = (result * 26) + (c - 65);
    }

    return result + 1;
}