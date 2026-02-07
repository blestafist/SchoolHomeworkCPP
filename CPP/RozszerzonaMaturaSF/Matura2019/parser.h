#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <fstream>
#include <sys/types.h>

// ===================== CONFIGURATION =====================

const int DIMENSIONS = 30;

const std::string INPUT_FILE = "dzialki.txt";
const std::string OUTPUT__FILE = "wynik4.txt";

const int FILE_LENGTH = 50;

const float PERCENTAGE_OF_GRASS = 0.7f;

// =========================================================

void ParseNext(std::ifstream& inputFile, char (&outputArr)[DIMENSIONS][DIMENSIONS]);

void DisplayArr(char (&arr)[DIMENSIONS][DIMENSIONS]);

bool IsGrass(const char (&arr)[DIMENSIONS][DIMENSIONS]);

bool SameAfterReverse(const char (&arr)[DIMENSIONS][DIMENSIONS]);

short MaxSquare(const char (&arr)[DIMENSIONS][DIMENSIONS]);

#endif
