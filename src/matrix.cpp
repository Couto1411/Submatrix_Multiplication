#include "matrix.hpp"
int **readMatrix(int coords[4]){
    std::fstream sample;
    coords[0]++;coords[2]++;
    int i=0,j=0,rows = coords[2]-coords[0]+1, cols = coords[3]-coords[1]+1, temp;
    sample.open("arquivos/matrix.txt");
    int** intMatrix = new int*[rows];
    for (int i = 0; i < rows; i++)
        intMatrix[i] = new int[cols];
    for (i = 0; i < coords[0]; i++) {
        sample.std::istream::ignore(40000000, '\n');
    }
    for (int i = coords[0]; i < (coords[2]); i++)
    {
        for (int j = coords[1]; j < (coords[3]); j++)
            printf("%d,%d ",i,j);
        printf("\n");
    }
    for (i = 0; i < rows; i++) {
        for (j = 0; j < coords[1]; j++) {
            sample >> temp;
        }
        for (j = 0; j < cols; j++) {
            sample >> intMatrix[i][j];
            printf("%d\n",intMatrix[i][j]);
        }
        sample.std::istream::ignore(40000000, '\n');
    }
    sample.close();
    return intMatrix;
}

int** mulMat(int **matA, int **matB, int coords[4]) {
    int R1 = coords[2]-coords[0]+1, R2 = coords[3]-coords[1]+1, C2=R1;
    int** rslt = new int*[R1];
    for (int i = 0; i < R1; ++i)
        rslt[i] = new int[C2];
    for (int i = 0; i < R1; i++) {
        for (int j = 0; j < C2; j++) {
            rslt[i][j] = 0;
            for (int k = 0; k < R2; k++)
                rslt[i][j] += matA[i][k] * matB[k][j];
        }
    }
    return rslt;
}

int** transpose(int **A,int coords[4]) {
    int i, j, rows=coords[2]-coords[0]+1, cols=coords[3]-coords[1]+1;
    int** B = new int*[cols];
    for (int i = 0; i < cols; ++i)
        B[i] = new int[rows];
    for (i = 0; i < cols; i++){
        for (j = 0; j < rows; j++)
            B[i][j] = A[j][i];
    }
    return B;
}

void printMatrix(Entry *mat){
    for (int i = 0; i < (mat->coordenadas[2]-mat->coordenadas[0]+1); i++)
    {
        for (int j = 0; j < (mat->coordenadas[2]-mat->coordenadas[0]+1); j++)
            printf("%d ",mat->value[i][j]);
        printf("\n");        
    }
}