#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void write_to_answer(int *candidate, int n, int *index, int **answer) {
    int i;
    for (i = 0; i < n; i++)
    {
        answer[*index][i] = candidate[i];
    }
}

void labeled_dfs(int n, int k, int start, int* count, int* line_count, int* oneline, int**answer) {
    int i;
    if (*count == k)
    {
        write_to_answer(oneline, k, line_count, answer);
        *line_count += 1;
        return;
    }
    for (i = start; i < n; i++) // start from what we haven't meet yet.
    {
        oneline[*count] = i+1;
        *count += 1;
        start += 1; 
        labeled_dfs(n, k, start, count, line_count, oneline, answer);
        *count -= 1;
    }
    return;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** combine(int n, int k, int** columnSizes, int* returnSize) {
    int i = 0;
    int oneline[k];
    int count = 0;
    int line_count = 0;
    int start = 0;
    
    if(n == 0 || k == 0 || n < k)
    {
        return NULL;
    }
    int **answer = (int**)malloc(sizeof(int*) * 20000);
    for (i = 0; i < 20000; i++)
    {
        answer[i] = (int*)malloc(sizeof(int) * k);
    }

    *columnSizes = (int*)malloc(sizeof(int) * 20000);

    labeled_dfs(n, k, start, &count, &line_count, oneline, answer);
    *returnSize = line_count;
    for (i = 0; i < (*returnSize); i++)
    {
        (*columnSizes)[i] = k;
    }
    return answer;
}

int main(void) {
    int n = 5;
    int k = 2;
    int i, j;
    int** answer;
    int *columnSizes = NULL;
    int returnSize = 0;
    answer = combine(n, k, &columnSizes, &returnSize);
    //printf("returnsize = %d\n", returnSize);
    for (i = 0; i < returnSize; i++)
    {
        for (j = 0; j <k; j++)
        {
            printf("%d, ", answer[i][j]);
        }
        printf("\n");
    }
        
}
