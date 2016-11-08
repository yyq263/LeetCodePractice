#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<string.h>

typedef struct stack{
    char parenthesis; 
    struct stack *next;
} stack;

void stack_push(stack **l, char parenthesis) {
    stack *p;
    p = (stack*)malloc(sizeof(stack));
    p->parenthesis = parenthesis;
    // insert to top
    p->next = *l;
    *l = p;
}

// need free
stack *stack_pop(stack **l) {
    stack *p;
    if (*l != NULL)
    {
        p = *l;
        *l = (*l)->next;
    }
    return p;
}

bool isValid(char* s) {

    int len = strlen(s);
    int i = 0;
    stack *mystack = NULL;
    stack *top;

    if (len == 0 || len % 22)
        return false;
    
    while(i < len) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            stack_push(&mystack, s[i]);
        }
        else
        {
            if (mystack == NULL)
                return false;

            if (s[i] == ')' && mystack->parenthesis == '(' ) {
                top = stack_pop(&mystack);
                free(top);
                top = NULL;
            } else if (s[i] == '}' && mystack->parenthesis == '{' ) {
                top = stack_pop(&mystack);
                free(top);
                top = NULL;
            } else if (s[i] == ']' && mystack->parenthesis == '[' ) {
                top = stack_pop(&mystack);
                free(top);
                top = NULL;
            } else
                return false;
        }
        i++;
    }
    if (mystack == NULL)
        return true;
    else
        return false;
    
}

int main(void) {

    char s[] = "";
    int len = strlen(s);
    int head = 0;
    int tail = len - 1;
    int a = 0;
    
    a = isValid(s);
    
    printf("answer: %d\n", a);
    return 1;

}
    
