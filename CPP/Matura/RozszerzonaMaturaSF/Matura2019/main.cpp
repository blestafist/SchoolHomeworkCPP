#include "parser.h"

#include <fstream>
#include <vector>
#include <limits.h>

// YOU CAN EDIT CONFIGURAION (FILE NAMES, DIMENSIONS) IN parser.h

int main() {
    std::ifstream inputFile (INPUT_FILE);

    if (!inputFile.is_open()) { std::cout << "Error while reading the file!"; }
    
    char arr[DIMENSIONS][DIMENSIONS];
    int grassCounter = 0, maxSquare = INT_MIN, square;

    std::vector<int> numberReverse, numberSqare;

    for (int i = 0; i < FILE_LENGTH; i++) {
        ParseNext(inputFile, arr);
        if (IsGrass(arr)) { grassCounter++; }
        if (SameAfterReverse(arr)) { std::cout << "Finally"; numberReverse.push_back(i + 1); }

        square = MaxSquare(arr);

        if (square > maxSquare) {
            numberSqare.clear();
            maxSquare = square;
            numberSqare.push_back(i + 1);
        }
        else if (square == maxSquare) { numberSqare.push_back(i + 1); }
    }

    inputFile.close();

    std::ofstream outputFile (OUTPUT__FILE);

    std::cout << "Ilość działek, w " << PERCENTAGE_OF_GRASS * 100 << "\% porośniętych trawą: " << grassCounter;

    // if (numberReverse.size() != 2) { std::cout << "\n\nLogic error in Task 2!"; return -1; }
    // std::cout << "\n\nNumery palindromicznych działek: " << numberReverse[0] << " i " << numberReverse[1];

    std::cout << "\n\nMaksymalny bok: " << maxSquare << "\n";
    for (int c : numberSqare) { std::cout << c << "\n"; }

    return 0;
}
