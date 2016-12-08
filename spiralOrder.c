#include<stdlib.h>
#include<string.h>
#include<stdio.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize) {
    int l=0, d=0, r=0, u=0;
    int rCol = matrixColSize - 1;
    int lCol = 0;
    int uRow = 0;
    int dRow = matrixRowSize - 1;
    int i = 0;
    int *s = (int*)malloc(sizeof(int) * matrixRowSize * matrixColSize);

    if (matrixRowSize == 0 && matrixColSize == 0)
        return NULL;
    
    while(i < (matrixRowSize * matrixColSize))
    {
        // Go right        
        while(uRow <= dRow && r <= rCol)
        {
            s[i++] = matrix[uRow][r++];
        }
        uRow++;
        d = uRow; // Go down
        while(rCol >= lCol && d <= dRow)
        {
            s[i++] = matrix[d++][rCol];
        }
        rCol--;
        l = rCol; // Go left
        while(dRow >= uRow && l >= lCol)
        {
            s[i++] = matrix[dRow][l--];
        }
        dRow--;
        u = dRow; // Go up
        while(lCol <= rCol && u >= uRow)
        {
            s[i++] = matrix[u--][lCol];
        }
        lCol++;
        r = lCol;
    }
    return s;
}

int main(void)
{
    int i, j;
    int *answer = NULL;
    int **matrix = (int**)malloc(sizeof(int) * 4);
    for (i = 0; i < 4; i++)
    {
        matrix[i] = (int*)malloc(sizeof(int) * 4);
    }
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            matrix[i][j] = i * 4 + j;
        }
    }
    
    answer = spiralOrder(matrix, 4, 4);

    for (i = 0; i < 16; i++)
    {
        printf("%d, ", answer[i]);
    }
    printf("\n");
}
