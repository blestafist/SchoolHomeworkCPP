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

int mySqrt(int x) {
    if (x < 2) { return x; }

    int left = 2, right = x / 2;
    int mid, res = 1;

    while (left <= right) {
        mid = left + (right - left) / 2;

        if (mid <= x / mid) //x eq to mid * mid <= x
        {
            res = mid; // remebmering a possible result
            left = mid + 1;
        }
        else { right = mid - 1; }
    }

    return res;
}