#ifndef SUBMATRIX_H 
#define SUBMATRIX_H
#include "hash.hpp"
#include <fstream>
#include <string.h>

int **readMatrix(int coords[4]);
int** mulMat(int **matA, int **matB, int coords[4]);
int** transpose(int **A,int coords[4]);
void printMatrix(Entry *mat);

#endif