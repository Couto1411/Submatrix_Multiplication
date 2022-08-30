#include "hash.hpp"

void criaHash(Table** t,int tam){
	(*t) = new Table;
    (*t)->quantidade = 0;
	(*t)->collisions =0;
    (*t)->tamanho = proxPrimo(2*tam);
    (*t)->table = new Entry*[(*t)->tamanho];
	for (int i = 0; i < (*t)->tamanho; i++)
		(*t)->table[i]= nullptr;
	
}

void insertHash(Table* t, int **multiplicacao, int *coords){
	int achou=0;
	int index = Hash1(coords) % t->tamanho;
	if (t->table[index] != nullptr){
		index = (Hash1(coords)*index+t->tamanho)%t->tamanho;
		while (t->table[index]!=nullptr&&achou<2){
			index++;
			if (index>=t->tamanho){
				index=0;
				achou+=1;
			}
			t->collisions+=1;
		}
		t->collisions+=1;
	}
	if ((float)t->quantidade / t->tamanho >= 1){
		Table* nova;
		criaHash(&nova,t->tamanho);
		for (int i = 0; i < t->tamanho; i++)
		{
			if (t->table[i]!=nullptr){
				insertHash(nova,t->table[i]->value,t->table[i]->coordenadas);
			}
		}
		t->table=nova->table;
		t->quantidade=nova->quantidade;
		t->collisions+=nova->collisions;
		t->tamanho=nova->tamanho;
		free(nova);
		insertHash(t,multiplicacao,coords);
	}
	else{
		t->table[index] = new Entry;
		t->table[index]->key = index;
		t->table[index]->value = multiplicacao;
		for (int i = 0; i <= 4; i++)
			t->table[index]->coordenadas[i] = coords[i];
		t->quantidade++;
	}
}

void removeHash(Table* t, int *coords){
	int achou=0,diminui=0;
	int index = Hash1(coords)% t->tamanho;
	if (t->table[index] != nullptr && t->table[index]->coordenadas==coords){
		free(t->table[index]);
		t->table[index]=nullptr;
		t->quantidade--;
	}
	else{
		index = (Hash1(coords)*index+t->tamanho)%t->tamanho;
		while ((t->table[index]==nullptr||t->table[index]->coordenadas!=coords)&&achou<2){
			index++;
			if (index>=t->tamanho){
				index=0;
				achou+=1;
			}
			diminui+=1;
		}
		diminui+=1;
		if (achou<2){
			free(t->table[index]);
			t->table[index]=nullptr;
			t->quantidade--;
			t->collisions=t->collisions-diminui;
		}
	}
}

Entry* searchHash(Table* t, int coords[4]){
	int achou=0;
	int index = Hash1(coords) % t->tamanho;
	if (t->table[index] != nullptr && t->table[index]->coordenadas[0]==coords[0] && t->table[index]->coordenadas[1]==coords[1] && t->table[index]->coordenadas[2]==coords[2] && t->table[index]->coordenadas[3]==coords[3])
		return t->table[index];
	else{
		index = (Hash1(coords)*index+t->tamanho)%t->tamanho;
		while ((t->table[index]==nullptr||t->table[index]->coordenadas[0]!=coords[0] || t->table[index]->coordenadas[1]!=coords[1] || t->table[index]->coordenadas[2]!=coords[2] || t->table[index]->coordenadas[3]!=coords[3])&&achou<2){
			index++;
			if (index>=t->tamanho){
				index=0;
				achou+=1;
			}
		}
		if (achou<2)
			return t->table[index];
	}
	return nullptr;
}

void printHash(Table* t){
	printf("Hash de tamanho: %d\n",t->tamanho);
	for (int k = 0; k < t->tamanho; k++)
	{
		if (t->table[k]!=nullptr){
		printf("%d: \n",k);
			for (int i = 0; i < (t->table[k]->coordenadas[2]-t->table[k]->coordenadas[0]+1); i++)
			{
				for (int j = 0; j < (t->table[k]->coordenadas[2]-t->table[k]->coordenadas[0]+1); j++)
					printf("%d ",t->table[k]->value[i][j]);
				printf("\n");
			}
		}
	}
	printf("Houveram %d colisoes.\n\n", t->collisions);
}

bool ePrimo(int n){
    if (n <= 1)  return false;
    if (n <= 3)  return true;

    if (n%2 == 0 || n%3 == 0) return false;
   
    for (int i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
           return false;

    return true;
}

int proxPrimo(int N){
    if (N <= 1)
        return 2;
 
    int prime = N;
    bool found = false;

    while (!found) {
        prime++;
        if (ePrimo(prime))
            found = true;
    }
 
    return prime;
}

int Hash1(int *coords){
	int num1 = coords[0];
	int num2 = coords[1];
	int num3 = coords[2];
	int num4 = coords[3];
	int result = (3*num1)+(7*num2)+(2*num3)+(num4);
	return result;
}

void printMatrixH(int **mat, int n, int m ){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%d ",mat[i][j]);
        printf("\n");        
    }
}

