#include "matrix.hpp"

int main(){
	Table *hash;
	Entry *existente;
	criaHash(&hash,1);
	int** Matriz, **Transposta;
	int *coordenadas;

	// Insere um termo
	coordenadas = new int[4]{0,0,3,4};
	Matriz=readMatrix(coordenadas);
	Transposta=transpose(Matriz,coordenadas);
	insertHash(hash, mulMat(Matriz,Transposta,coordenadas),coordenadas);

	// Insere segundo termo
	coordenadas = new int[4]{1,1,5,5};
	existente=searchHash(hash,coordenadas);
	// Caso seja encontrado mostra o resultado já feito
	if(existente==nullptr){
		Matriz=readMatrix(coordenadas);
		Transposta=transpose(Matriz,coordenadas);
		insertHash(hash, mulMat(Matriz,Transposta,coordenadas),coordenadas);
	}
	else{
		printf("Multiplicação já inserida, resultado:\n");
		printMatrix(existente);
	}

	// Insere terceiro termo
	coordenadas = new int[4]{1,1,4,7};
	existente=searchHash(hash,coordenadas);
	// Caso seja encontrado mostra o resultado já feito
	if(existente==nullptr){
		Matriz=readMatrix(coordenadas);
		Transposta=transpose(Matriz,coordenadas);
		insertHash(hash, mulMat(Matriz,Transposta,coordenadas),coordenadas);
	}
	else{
		printf("Multiplicação já inserida, resultado:\n");
		printMatrix(existente);
	}
	printHash(hash);

	// Insere quarto termo
	coordenadas = new int[4]{1,1,5,5};
	existente=searchHash(hash,coordenadas);
	// Caso seja encontrado mostra o resultado já feito
	if(existente==nullptr){
		Matriz=readMatrix(coordenadas);
		Transposta=transpose(Matriz,coordenadas);
		insertHash(hash, mulMat(Matriz,Transposta,coordenadas),coordenadas);
	}
	else{
		printf("Multiplicação já inserida, resultado:\n");
		printMatrix(existente);
	}
	printHash(hash);
	return 0;
}
