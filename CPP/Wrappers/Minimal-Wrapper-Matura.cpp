#include <iostream>
#include <fstream>

const std::string INPUT_FILE_NAME = "";
const std::string OUTPUT_FILE_NAME = "";

int main()
{
    std::ifstream inputFile(INPUT_FILE_NAME);
    if (!inputFile) { std::cerr << "Error while opening inputFile\n"; return -1; }

    std::ofstream outputFile(OUTPUT_FILE_NAME);
    if (!outputFile) { std::cerr << "Error while opening outputFile\n"; return -1; }

    std::string tempString;

    while (inputFile >> tempString)
    {

    }
}