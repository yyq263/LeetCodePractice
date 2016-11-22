#include<stdlib.h>
#include<string.h>
#include<stdio.h>


typedef struct stack{
    int candidate;
    int index;
    struct stack *next;
} stack;

void stack_push(stack **l, int candidate, int index) { //Remember the index too.
    stack *p;
    p = (stack*)malloc(sizeof(stack));
    p->candidate = candidate;
    p->index = index;
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
    stack* pop;
    int nextIndex = 0;

    while(sum < target)
    {

        sum += candidate[candidateIndex];
        stack_push(route, candidate[candidateIndex], candidateIndex);
        printf("candidate=%d\n", candidate[candidateIndex]);
        //printf("sum=%d\n", sum);
        if (sum == target)
        {
            ans[*ansIndex] = rememberRoute(*route, &ansLen[*ansIndex]);
            *ansIndex += 1;
        }
    }
    pop = stack_pop(route); // Pop the element that makes the sum of route greater than or equal to target.
    if (pop != NULL)
    {
        //printf("pop=%d\n", pop->candidate);
        nextIndex = pop->index + 1;
        sum -= pop->candidate;
        free(pop);
    }

    pop = stack_pop(route); // Pop twice makes sense because we have an ordered array!
    if (pop != NULL)
    {
        //printf("pop=%d\n", pop->candidate);
        nextIndex = pop->index + 1;
        sum -= pop->candidate;
        free(pop);
    }
    printf("nextIndex: %d\n", nextIndex);
    printf("size: %d\n", size);
    if (nextIndex >= size)// If there are entries left...
    {
        printf("routeIndex=%d\n", (*route)->index);
        if (*route != NULL && ((*route)->index + 1) < size)
        {
            printf("1\n");
            pop = stack_pop(route);
            nextIndex = pop->index + 1;
            sum -= pop->candidate;
            free(pop);
            searchForRoute(candidate, nextIndex, size, target, sum, route, ans, ansIndex, ansLen);
        }
        else
            return;
    }
    else
        searchForRoute(candidate, nextIndex, size, target, sum, route, ans, ansIndex, ansLen);
    
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
