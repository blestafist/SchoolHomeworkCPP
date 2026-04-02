#include <iostream>
#include <fstream>


// ====================================== CONFIGURATION ===================================

const std::string INPUT_FILE_NAME = "gra.txt";
const std::string OUTPUT_FILE_NAME = "wyniki_5.txt";
 
const unsigned char DIMENSION_Y = 12; 
const unsigned char DIMENSION_X = 20;

const char Y_OFFSET [8] { -1, -1, -1, 0, 0, 1, 1, 1 };
const char X_OFFSET [8] { -1, 0, 1, -1, 1, -1, 0, 1 };

// ========================================================================================


int AliveNeighboursCount (const char (&generation)[DIMENSION_Y][DIMENSION_X], int y, int x)  // Count of alive neighbours around the cell
{
    int counter = 0;

    for (int i = 0; i < 8; i++)
    {
        int nY = (y + Y_OFFSET[i] + DIMENSION_Y) % DIMENSION_Y;
        int nX = (x + X_OFFSET[i] + DIMENSION_X) % DIMENSION_X;

        if (generation[nY][nX] == 'X') { counter++; }
    }
    return counter;
}


bool IsCellAlive (char (&generation)[DIMENSION_Y][DIMENSION_X], int y, int x)   // Checks if the cell is alive in the next generation
{
    int AliveNeighbours = AliveNeighboursCount(generation, y, x);

    if (generation[y][x] == 'X') { return AliveNeighbours == 2 || AliveNeighbours == 3; }  // Conditions of cell live in a new generation
    else { return AliveNeighbours == 3; }
}


void SimulateGen (char (&generation)[DIMENSION_Y][DIMENSION_X], int num)    // Simulates the life of cells in a selected generation
{
    if (num <= 1) { return; }

    char helperGen[DIMENSION_Y][DIMENSION_X];

    for (int y = 0; y < DIMENSION_Y; y++)
    {
        for (int x = 0; x < DIMENSION_X; x++)   // Goes throught previous generation
        {
            IsCellAlive(generation, y, x) ? helperGen[y][x] = 'X' : helperGen[y][x] = '.';    
        }
    }

    for (int y = 0; y < DIMENSION_Y; y++)   // Copy to original array
    {
        for (int x = 0; x < DIMENSION_X; x++)
        {
            generation[y][x] = helperGen[y][x];
        }
    }

    SimulateGen(generation, num - 1);
}


int main()
{
    std::ifstream inputFile(INPUT_FILE_NAME);
    if (!inputFile) { std::cerr << "Error while opening inputFile\n"; return -1; }

    std::ofstream outputFile(OUTPUT_FILE_NAME);
    if (!outputFile) { std::cerr << "Error while opening outputFile\n"; return -1; }

    char crrGen[DIMENSION_Y][DIMENSION_X];

    for (int y = 0; y < DIMENSION_Y; y++)    
    {
        for (int x = 0; x < DIMENSION_X; x++)   // Fill the 2D array of first generation 
        {
            inputFile >> crrGen[y][x];
        }
    }

    int genNum = 2;

    while (genNum <= 100)
    {
        char prevGen[DIMENSION_Y][DIMENSION_X]; 

        for (int y = 0; y < DIMENSION_Y; y++)
        {
            for (int x = 0; x < DIMENSION_X; x++)
            {
                prevGen[y][x] = crrGen[y][x];   // Copy current generation to previous
            }
        }

        SimulateGen(crrGen, 2);

        bool flag = true;

        for (int y = 0; y < DIMENSION_Y; y++)
        {
            for (int x = 0; x < DIMENSION_X; x++)
            {
                if (crrGen[y][x] != prevGen[y][x]) { flag = false; }     // If the whole cells is equal subflag becomes true
            }
        }

        if (flag) { break; }
        
        genNum++;
    }
    
    int cellsCounter = 0;

    for (int y = 0; y < DIMENSION_Y; y++)
    {
        for (int x = 0; x < DIMENSION_X; x++)
        {
            if (crrGen[y][x] == 'X') { cellsCounter++; }
        }
    }
    
    std::cout << "C\nW pokoleniu nr " << genNum <<", liczba żywych komórek : " << cellsCounter;
    outputFile << "C\nW pokoleniu nr " << genNum <<", liczba żywych komórek : " << cellsCounter;
}