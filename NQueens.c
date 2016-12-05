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

void constructAnswers(int n, stack* preQueens, char*** answer) {
    int i = 0;
    char line[n + 1] ;
    stack* tmp = NULL;

    for (i = 0; i < n; i++)
    {
        line[i] = '.';
    }
    line[n] = '\0';
    
    *answer = (char**)malloc(sizeof(char*) * n);
    tmp = preQueens;
    for (i = 0; i < n; i++)
    {
        line[tmp->Q] = 'Q';
        (*answer)[i] = (char*)malloc(sizeof(char) * (n + 1));
        strcpy((*answer)[i], line);
        line[tmp->Q] = '.';
        //printf("answer: %s\n", (*answer)[i]);
        tmp = tmp->next;
    }
}

void helper(int n, int lineNumber, stack** preQueens, char*** answer, int* returnSize) {
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
                constructAnswers(n, *preQueens, &answer[*returnSize]);
                (*returnSize)++;
            }
            helper(n, lineNumber + 1, preQueens, answer, returnSize);
            stack_pop(preQueens);
        }
        else {
            //printf("discard: [%d, %d]\n",lineNumber, i);
        }
    }
    return;
}
    

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char*** solveNQueens(int n, int* returnSize) {
    stack* preQueens = NULL;
    char ***ans = NULL;

    ans = (char***)malloc(sizeof(char**) * 10000);
    memset(ans, 0, sizeof(ans) );
    
    if (n == 0 || n == 2 || n == 3)
    {
        *returnSize = 0;
        return NULL;
    }
    if (n == 1)
    {
        ans[0] = (char**)malloc(sizeof(char*));
        ans[0][0] = (char*)malloc(sizeof(char) * 2);
        ans[0][0][0] = 'Q';
        ans[0][0][1] = '\0';
        *returnSize = 1;
        return ans;
    }
    
    *returnSize = 0;
    
    helper(n, 0, &preQueens, ans, returnSize);

    return ans;
}

int main(void){
    int n = 9;
    int returnSize = 0;
    char*** ans = solveNQueens(n, &returnSize);
    int i, j ;

    
    //printf("ans length = %d\n", returnSize);

    for (i = 0; i < returnSize; i++)
    {
        for (j = 0 ; j < n; j++)
        {
            printf("%s\n", ans[i][j]);
        }
        printf("\n");
    }
    
}


