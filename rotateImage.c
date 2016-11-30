#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void rotate(int** matrix, int matrixRowSize, int matrixColSize) {
    int i, j;
    int tmp;
    int n;

    if (matrixRowSize == 0 || matrixColSize == 0)
    {
        return;
    }
    n = matrixRowSize;
    for (i = 0; i < n - 1; i++) // flip along diagonal
    {
        for (j = 0; j < n - i; j++)
        {
            printf("i=%d, j=%d\n", i, j);
            tmp = matrix[i][j];
            matrix[i][j] = matrix[n - 1 - j][n - 1 - i];
            matrix[n - 1 - j][n - 1 - i] = tmp;
        }
    }
    for (i = 0; i < (matrixRowSize / 2); i++) // filp horizontally
    {
        for (j = 0; j < matrixColSize; j++)
        {
            tmp = matrix[i][j];
            matrix[i][j] = matrix[n - 1 - i][j];
            matrix[n - 1 - i][j] = tmp;

        }
    }
}

int main(void) {
    int a[3][3] = {{1,2,3},{4,5,6},{7,8,9}} ;
    int matrixRowSize = 3;
    int matrixColSize = 3;
    int i,j;
    int *s[3]; // s stores 3 pointers point to 3 arrays
    s[0] = a[0];
    s[1] = a[1];
    s[2] = a[2];
    rotate(s, matrixRowSize, matrixColSize);

    for(i = 0; i < matrixRowSize; i++)
    {
        for(j = 0; j < matrixColSize; j++)
        {
            printf("%d, ", s[i][j]);
        }
        printf("\n");
    }


}
