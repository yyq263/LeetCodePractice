#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct stack{
    int Q;
    int lineNumber;
    struct stack *next;
} stack;

void stack_push(stack **l, int Q, int lineNumber) {
    stack *p;
    p = (stack*)malloc(sizeof(stack));
    p->Q = Q;
    p->lineNumber = lineNumber;
    // insert to top
    p->next = *l;
    *l = p;
}
// a free version
void stack_pop(stack **l){
    stack* p;
    if (*l != NULL) {
        p = *l;
        *l = (*l)->next;
        free(p);
        p = NULL;
    }
}

int isValidPos(int index, int lineNumber, int n, stack* preQueens) {
    stack* tmp = NULL;
    int diff;
    if (lineNumber == 0)
        return 1;
    for (tmp = preQueens; tmp != NULL; tmp = tmp->next)
    {
        diff = lineNumber - tmp->lineNumber;
        if (index == tmp->Q || index == tmp->Q + diff || index == tmp->Q - diff)
        {
            return 0;
        }
    }
    return 1;
}


void helper(int n, int lineNumber, stack** preQueens, int* returnSize) {
    int i;

    //printf("line number = %d\n", lineNumber);
    if (lineNumber >= n)
        return;

    for (i = 0; i < n; i++)
    {
        if (isValidPos(i, lineNumber, n, *preQueens))
        {
            //printf("store: [%d, %d]\n",lineNumber, i);
            stack_push(preQueens, i, lineNumber);
            if (lineNumber == n - 1)
            {
                //printf("FIND ANSWER!\n");
                (*returnSize)++;
            }
            helper(n, lineNumber + 1, preQueens, returnSize);
            stack_pop(preQueens);
        }
    }
    return;
}
    

int totalNQueens(int n) {
    stack* preQueens = NULL;
    int returnSize = 0;
    
    if (n == 0 || n == 2 || n == 3)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    
    helper(n, 0, &preQueens, &returnSize);

    return returnSize;
}

int main(void){
    int n = 6;
    int returnSize = 0;
    int N = totalNQueens(n);
    int i, j ;
    
    printf("%d\n", N);

    
}


