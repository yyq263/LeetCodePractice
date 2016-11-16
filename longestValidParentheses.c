#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX(x, y) (x > y ? x : y)

typedef struct stack{
    int index;
    char parenthesis; 
    struct stack *next;
} stack;

void stack_push(stack **l, char parenthesis, int index) {
    stack *p;
    p = (stack*)malloc(sizeof(stack));
    p->parenthesis = parenthesis;
    p->index = index;
    // insert to top
    p->next = *l;
    *l = p;
}

// need free after pop!
stack *stack_pop(stack **l) {
    stack *p = NULL;
    if (*l != NULL)
    {
        p = *l;
        *l = (*l)->next;
    }
    return p;
}

int longestValidParentheses(char* s) {
    int i;
    int len = strlen(s);
    int max=0, now=0; 
    stack* sk = NULL;
    stack* top;
    if(len < 2)
        return 0;
    for (i = 0; i < len; i++)
    {
        if (s[i] == '(') {
            stack_push(&sk, s[i], i);
        }
        else // s[i] == ')'
        {
            if (sk != NULL && sk->parenthesis == '(')
            {
                now = 0;
                top = stack_pop(&sk);
                free(top);
                top = NULL;
                if (sk == NULL) {
                    now = i + 1;
                }
                else
                {
                    now = i - sk->index;
                }
                max = MAX(now, max);
            }
            else 
            {
                stack_push(&sk, s[i], i);
            }
        }
    }
    return max;
}

int main(void) {
    char s[] = ")(())()";
    int ans = longestValidParentheses(s);

    printf("ans=%d\n", ans);
    
}
