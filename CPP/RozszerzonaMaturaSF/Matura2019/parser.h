#ifndef PARSER_H
#define PARSER_H

// ===================== CONFIGURATION =====================

const int DIMENSIONS = 30;

// =========================================================

#include <iostream>
#include <fstream>

void ParseNext(std::ifstream& inputFile, char (&outputArr)[DIMENSIONS][DIMENSIONS]);

bool IsGrass(const char (&arr)[DIMENSIONS][DIMENSIONS]);

bool SameAfterReverse(const char (&arr)[DIMENSIONS][DIMENSIONS]);

short MaxSquare(const char (&arr)[DIMENSIONS][DIMENSIONS]);

#endif