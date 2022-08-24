#ifndef HASHTABLE_H 
#define HASHTABLE_H

#include  <iostream>

struct Entry {
	int key;
	int coordenadas[4];
	int **value;
};

struct Table {
    Entry** table;
	int tamanho;
	int quantidade;
	int collisions;
};

void printHash(Table* t);
void criaHash(Table** t,int tam);
void insertHash(Table* t, int **multiplicacao, int *coords);
void removeHash(Table* t, int *coords);
Entry* searchHash(Table* t, int *coords);
bool ePrimo(int n);
int proxPrimo(int N);
int Hash1(int coords[4]);
void printMatrixH(int **mat, int n, int m );
#endif