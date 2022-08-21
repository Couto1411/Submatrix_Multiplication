#include "matrix.hpp"

int main(){
	Table *hash;
	Entry *existente;
	hash=criaHash(1);
	int** Matriz, **Transposta;
	int *coordenadas;
	coordenadas = new int[4];
	coordenadas[0]=0;
	coordenadas[1]=0;
	coordenadas[2]=4;
	coordenadas[3]=5;
	Matriz=readMatrix(coordenadas);
	Transposta=transpose(Matriz,coordenadas);
	insertHash(hash, mulMat(Matriz,Transposta,coordenadas),coordenadas);
	coordenadas[0]=1;
	coordenadas[1]=1;
	coordenadas[2]=5;
	coordenadas[3]=5;
	Matriz=readMatrix(coordenadas);
	Transposta=transpose(Matriz,coordenadas);
	existente=searchHash(hash,coordenadas);
	if(existente==nullptr)
		insertHash(hash, mulMat(Matriz,Transposta,coordenadas),coordenadas);
	else{
		printf("Multiplicação já inserida, resultado:\n");
		printMatrix(existente);
	}
	coordenadas[0]=0;
	coordenadas[1]=0;
	coordenadas[2]=4;
	coordenadas[3]=5;
	Matriz=readMatrix(coordenadas);
	Transposta=transpose(Matriz,coordenadas);
	existente=searchHash(hash,coordenadas);
	if(existente==nullptr)
		insertHash(hash, mulMat(Matriz,Transposta,coordenadas),coordenadas);
	else{
		printf("Multiplicação já inserida, resultado:\n");
		printMatrix(existente);
	}
	printHash(hash);
	coordenadas[0]=3;
	coordenadas[1]=3;
	coordenadas[2]=5;
	coordenadas[3]=5;
	Matriz=readMatrix(coordenadas);
	Transposta=transpose(Matriz,coordenadas);
	existente=searchHash(hash,coordenadas);
	if(existente==nullptr)
		insertHash(hash, mulMat(Matriz,Transposta,coordenadas),coordenadas);
	else{
		printf("Multiplicação já inserida, resultado:\n");
		printMatrix(existente);
	}
	printHash(hash);
	return 0;
}
