#include <iostream>

int main() {
    int arr[6] = {1, -2, 6, -5, 7, -3};

    int localSum = 0,
    maxSum = 0,
    currInt;

    for (int i = 0; i < 6; i++) {
        localSum += arr[i];
        if (localSum < 0) {
            localSum = 0;
        }

        if (localSum > maxSum) { maxSum = localSum; }
    }

    std::cout << maxSum;
}
