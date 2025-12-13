#include <iostream>
#include <cstdint>

std::string Converter(int decimalNum, uint8_t sys) {
    std::string result = 0;
    char currentChar; 

    while (decimalNum > 0) {
        currentChar = decimalNum % sys + 48;
        result = result + currentChar;
        decimalNum /= 10;
    }

    return result;
}

int main() {
    uint8_t base;
    int numberToConvert;

    std::cout << "Give a number to convert: ";
    std::cin >> numberToConvert;

    std::cout << "Give a base: ";
    std::cin >> base;

    std::cout << "\n\n" << Converter(numberToConvert, base);
}