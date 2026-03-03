#include <cstdlib>
#include <iostream>
using namespace std;


int titleToNumber(string columnTitle) {
    int result = 0;

    for (char c : columnTitle) {
        int digit = c - 'A' + 1;
        result = (result * 26) + digit;
    }

    return result;
}


int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
    // ! A is a first rectangle
    // ! B is a second rectangle

    int rectangleCoverArea;
    rectangleCoverArea = abs(bx1 - ax2) * abs(by1 - ay2);
}