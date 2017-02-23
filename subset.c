#include<stdlib.h>
#include<stdio.h>
#include<string.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** subsets(int* nums, int numsSize, int** columnSizes, int* returnSize) {
    if (numsSize == 0)
        return NULL;
    int all = 1 << numsSize;
    int **answer = (int**)malloc(all * sizeof(int*));
    int i, j, index;
    
    *returnSize = all;
    *columnSizes = (int*)malloc(sizeof(int) * all);

    for (i = 0; i < all; i++)
    {
        //printf("i=%d\n", i);
        if (i == 0)
        {
            (*columnSizes)[0] = 0;
            answer[0] = NULL;
            continue;
        }
        answer[i] = (int*)malloc(sizeof(int) * i);
        index = 0;
        for (j = 0; j < numsSize; j++)
        {
            if (i & (1 << j))  // key
            {
                answer[i][index++] = nums[j];
            }
        }
        (*columnSizes)[i] = index;
    }
    return answer;
}

int main(void) {
    int s[5] = {1,2,3,4,5};
    int n = 5;
    int i, j;
    int** answer;
    int *columnSizes = NULL;
    int returnSize = 0;
    answer = subsets(s, n, &columnSizes, &returnSize);
    //printf("returnsize = %d\n", returnSize);
    for (i = 0; i < returnSize; i++)
    {
        for (j = 0; j <columnSizes[i]; j++)
        {
            printf("%d, ", answer[i][j]);
        }
        printf("\n");
    }
        
}
