#include <iostream>

int CountSwaps(int num1, int num2) {
	int needSwap = 0; // logic type, set to false
	int swaps = 0;
	while (num1 > 0) {
		if ((num1 % 10) + (num2 % 10) + needSwap > 9) {
			needSwap = 1;
			++swaps;
		}
		else {
			needSwap = 0;
		}
		num1 /= 10;
		num2 /= 10;
	}

	return swaps;
}


int main() {
	std::cout << CountSwaps(27732, 72619);
}
