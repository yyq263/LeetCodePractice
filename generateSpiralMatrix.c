#include<stdlib.h>
#include<stdio.h>
#include<string.h>

/**
 * Return an array of arrays.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n) {
    int l=0, d=0, r=0, u=0;
    int rCol = n - 1;
    int lCol = 0;
    int uRow = 0;
    int dRow = n - 1;
    int i; 
    int **matrix = (int**)malloc(sizeof(int*) * n);
    for (i = 0; i < n; i++)
    {
        matrix[i] = (int*)malloc(sizeof(int) * n);
    }

    if (n == 0)
        return NULL;
    
    i = 1;
    
    while(i <= n * n)
    {

        // Go right        
        while(uRow <= dRow && r <= rCol)
        {
            matrix[uRow][r++] = i++;
        }
        uRow++;
        d = uRow; // Go down
        while(rCol >= lCol && d <= dRow)
        {
            matrix[d++][rCol] = i++;
        }
        rCol--;
        l = rCol; // Go left
        while(dRow >= uRow && l >= lCol)
        {
            matrix[dRow][l--] = i++;
        }
        dRow--;
        u = dRow; // Go up
        while(lCol <= rCol && u >= uRow)
        {
            matrix[u--][lCol] = i++;
        }
        lCol++;
        r = lCol;
    }
    return matrix;
}
int main(void)
{
    int i, j;
    int n = 5;
    int **matrix = generateMatrix(n);

    for (i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%d, ", matrix[i][j]);
        }
        printf("\n");
    }

}
