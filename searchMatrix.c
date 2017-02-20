#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>


bool binarySearch(int array[], int len, int target) {
    int beg = 0, end = len - 1;
    int i = (beg + end) / 2;

    while(beg <= end)
    {
        //printf("%d\n", array[i]);
        if (target == array[i])
            return true;
        else if (target < array[i])
            end = i - 1;
        else // target > array[i]
            beg = i + 1;
        i = (beg + end) / 2;
    }
    return false;
}

bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    int length = matrixRowSize * matrixColSize;
    int beg = 0, end = matrixRowSize;
    int i = (beg + end) / 2;
    
    if (matrix == NULL || *matrix == NULL)
        return false;

    if (target < matrix[0][0] || target > matrix[matrixRowSize - 1][matrixColSize - 1])
    {
        return false;
    }
    
    while(beg <= end)
    {
        if (target >= matrix[i][0] && target <= matrix[i][matrixColSize - 1] )
        {
            return binarySearch(matrix[i], matrixColSize, target);
        }
        else if (target < matrix[i][0])
        {
            end = i - 1;
        }
        else // target > matrix[i][matrixColSize - 1]
        {
            beg = i + 1;
        }
        i = (beg + end) / 2;
    }
    return false;
}

int main(void) {
    int *s[5];
    int i, j;
    int a1[4] = {1,3,4,5};
    int a2[4] = {9,13,21,34};
    int a3[4] = {35,41,51,64};
    int a4[4] = {67,72,81,93};
    int a5[4] = {100,200,341,441};
    s[0] = a1;
    s[1] = a2;
    s[2] = a3;
    s[3] = a4;
    s[4] = a5;

    printf("ans: %d\n", searchMatrix(s, 5, 4, 441));

}
