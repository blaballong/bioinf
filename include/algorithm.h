#ifndef _ALGORITHM
#define _ALGORITHM

#include "dna.h"
#include "helper.h"
#include "spectrum.h"

#include <string>

void init(std::string filepath);
void run();
void generateInitialSolution();
int getStartingNode();
int evaluateNode(int row, int column);
void generateMatrix();
void assignWeights();

#endif