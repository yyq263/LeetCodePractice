#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void setRowToZeros(int** matrix, int nthRow, int nCol) {
    int i;
    for (i = 0; i < nCol; i++)
        matrix[nthRow][i] = 0;
    return;
}

void setColToZeros(int** matrix, int nthCol, int nRow) {
    int i;
    for (i = 0; i < nRow; i++)
        matrix[i][nthCol] = 0;
    return;
}

void setZeroes(int** matrix, int matrixRowSize, int matrixColSize) {
    int i, j;
    int last[matrixColSize];
    int set_zero = 0;
    
    for (i = 0; i < matrixColSize; i++)
    {
        last[i] = 0;
    }
    for (i = 0; i < matrixRowSize; i++)
    {
        for (j = 0; j < matrixColSize; j++)
        {
            if (matrix[i][j] == 0) 
            {
                set_zero = 1; // 
                last[j] = 1; // Remember column number
                //printf("j=%d\n", j);
            }
            if ((j == matrixColSize - 1) && set_zero) // Set row to 0
            {
                setRowToZeros(matrix, i, matrixColSize);
                set_zero = 0;
            }
        }
    }
    for (i = 0; i < matrixColSize; i++)
    {
        if (last[i] == 1) // Set Column to 0
        {
            setColToZeros(matrix, i, matrixRowSize);
        }
    }
}

int main(void) {
    int *s[5];
    int i, j;
    int a1[4] = {0,0,0,5};
    int a2[4] = {4,3,1,4};
    int a3[4] = {0,1,1,4};
    int a4[4] = {1,2,1,3};
    int a5[4] = {0,0,1,1};
    s[0] = a1;
    s[1] = a2;
    s[2] = a3;
    s[3] = a4;
    s[4] = a5;

    setZeroes(s, 5, 4);
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%d, ",s[i][j]);
        }
        printf("\n");
    }
    return 1;
    
}
