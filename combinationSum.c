#include<stdlib.h>
#include<string.h>
#include<stdio.h>


typedef struct stack{
    int candidate;
    struct stack *next;
} stack;

void stack_push(stack **l, int candidate) { //Remember the index too.
    stack *p;
    p = (stack*)malloc(sizeof(stack));
    p->candidate = candidate;
    // insert to top
    p->next = *l;
    *l = p;
}

// need free
stack *stack_pop(stack **l) {
    stack *p = NULL;
    if (*l != NULL)
    {
        p = *l;
        *l = (*l)->next;
    }
    return p;
}

int* rememberRoute(stack* head, int* size) {

    stack* tmp = head;
    int i = 0;

    *size = 0;
    if (tmp == NULL)
        return NULL;
    while (tmp != NULL)
    {
        //printf("%d, ", tmp->candidate);
        (*size) += 1;
        tmp = tmp->next;
    }

    int *s = (int*)malloc(sizeof(int) * (*size));
    i = *size - 1;
    tmp = head;
    while (tmp != NULL)
    {
        s[i--] = tmp->candidate;
        tmp = tmp->next;
    }
    return s;
}

int cmpInt ( const void *a , const void *b )
{
    return *(int *)a - *(int *)b;
}

    

void searchForRoute(int* candidate, int candidateIndex, int size, int target, int sum, stack** route, int **ans, int* ansIndex, int *ansLen) {

    int i;
    if (sum > target)
        return;
    if (sum == target)
    {
        ans[*ansIndex] = rememberRoute(*route, &ansLen[*ansIndex]);
        *ansIndex += 1;
        return;
    }
    for (i = candidateIndex; i < size; i++)
    {
        stack_push(route, candidate[i]);
        searchForRoute(candidate, i, size, target, sum+candidate[i], route, ans, ansIndex, ansLen);
        stack* pop = stack_pop(route);
        free(pop);

    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** combinationSum(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize) {
    int i;
    int counter = 0;
    int sum = 0;
    stack* route = NULL;
    int **ans;
    int *ansLen;
    int ansIndex = 0;
    int candidateIndex = 0;

    ans = (int**)malloc(sizeof(int*) * 1024);
    ansLen = (int*)malloc(sizeof(int) * 1024);
    
    if (candidatesSize == 0)
        return NULL;

    qsort(candidates, candidatesSize, sizeof(int), cmpInt);

    if (candidates[0] > target)
        return NULL;

    searchForRoute(candidates, candidateIndex, candidatesSize, target, sum, &route, ans, &ansIndex, ansLen);

    *returnSize = ansIndex;

    *columnSizes = ansLen;
    
    return ans;
    
}

int main(void) {
    int s[] = {1,2};
    int target = 10;
    int size = sizeof(s) / sizeof(int);
    int returnSize = 0;
    int *columnSizes;
    int **ans;
    int i,j;
    
    ans = combinationSum(s, size, target, &columnSizes, &returnSize);
    printf("returnSize = %d\n", returnSize);
    for (i = 0; i < returnSize; i++)
    {
        printf("%d: ", columnSizes[i]);
        for (j = 0; j < columnSizes[i]; j++)
        {
            printf("%d, ", ans[i][j]);
        }
        printf("\n");
    }
    printf("\n");

}
