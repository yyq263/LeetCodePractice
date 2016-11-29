#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int cmpInt ( const void *a , const void *b )
{
    return *(int *)a - *(int *)b;
}

typedef struct stack{
    int x;
    struct stack *next;
} stack;

void stack_push(stack **l, int x) {
    stack *p;
    p = (stack*)malloc(sizeof(stack));
    p->x = x;
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


void helper(int* nums, int numsSize, int *s, int** ans, int* ansIndex, stack** ansStack) {
    int i = 0;
    stack* pop;

    for (i = 0; i < numsSize; i++)
    {
        if (s[i] == 1)
        {
            continue;
        }
        else
            break;
    }

    if (i == numsSize)
    {
        stack *tmp = *ansStack;
        for(i = numsSize - 1; i >= 0; i--)
        {
            printf("%d, ", tmp->x);
            ans[*ansIndex][i] = tmp->x;
            tmp = tmp->next;
        }
        printf("\n");
        (*ansIndex)++;
        return;
    }

    i = 0;
    while (i < numsSize)
    {
        if(s[i] == 0)
        {

            //printf("%d\n", nums[i]);
            s[i] = 1;
            stack_push(ansStack, nums[i]);
            helper(nums, numsSize, s, ans, ansIndex, ansStack);
            pop = stack_pop(ansStack);
            //printf("%d\n", pop->x);
            free(pop);
            pop = NULL;
            s[i] = 0;
            while (i + 1 < numsSize && nums[i] == nums[i + 1]) // If we have nums[i] == nums[i+1], we are having the same permutation, skip it.
                i++;
        }
        i++;
    }
}

int** permuteUnique(int* nums, int numsSize, int* returnSize) {
    int **ans; // size: numsSize! * numsSize * 4 bytes.
    int i;
    int index[numsSize];
    int ansSize = 10000;
    stack *ansStack = NULL;

    *returnSize = 0;
    
    if (numsSize == 0)
    {
        return NULL;
    }
    
    qsort(nums, numsSize, sizeof(int), cmpInt);
    
    for (i = 1; i <= numsSize; i++)
    {
        index[i - 1] = 0;
    }

    ans = (int**)malloc(sizeof(int*) * ansSize);
    
    for (i = 0; i < ansSize; i++)
    {
        ans[i] = (int*)malloc(sizeof(int) * numsSize);
    }

    helper(nums, numsSize, index, ans, returnSize, &ansStack);
    
    return ans;
}

int main(void) {
    int a[] = {1,2, 3,3};
    int len = sizeof(a)/ sizeof(int);
    int returnSize = 0;
    permuteUnique(a, len, &returnSize);
    printf("size = %d\n", returnSize);
    
}
    
