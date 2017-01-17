#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct stack{
    char* dir;
    struct stack *next;
} stack;

void push(stack** head, char* dir) {
    stack *p;
    p = malloc(sizeof(stack));
    p->dir = malloc(strlen(dir) + 1);
    memcpy(p->dir, dir, strlen(dir) + 1);
    p->next = *head;
    *head = p;
    return;
}

void free_node(stack* node) {
    free(node->dir);
    free(node);
}

void pop(stack** head) {
    stack *p = NULL;
    if (*head != NULL)
    {
        p = *head;
        *head = (*head)->next;
        free_node(p);
    }
    return;
}


char* simplifyPath(char* path) {
    char* p = path;
    stack* this_dir = NULL;
    int len = 0;
    char *name=NULL;
    int i;
    
    if (path == NULL)
    {
        return NULL;
    }
    
    while (*p != '\0')
    {
        if(*p == '/') /* We aim at '/', after handle one '/', we expect next '/'*/
        {
            ++p;
            if (*p == '/') /* case: // */
                ;
            else if (*p == '\0') /* case: EOL */
                break;
            else if (strncmp(p, "../", 3) == 0 || (strncmp(p, "..", 2) == 0 && *(p + 2) == '\0')) /* case: /../ or /.. */
            {
                pop(&this_dir);
                p+=2;
            }
            else if (strncmp(p, "./", 2) == 0 || (*p == '.' && *(p + 1) == '\0')) /* case: /./ or /. */
            {
                ++p;
            }
            else /* case: /directory_name or /directory_name/ */
            {
                while(*p != '/' && *p != '\0')
                {
                    ++len;
                    ++p;
                }
                name = (char*)malloc(len + 1);
                memcpy(name, p - len, len);
                name[len] = '\0';
                len = 0;
                push(&this_dir, name);
                //printf("%s\n", name);
                free(name);
                name = NULL;
            }
        }
        else /* neglect non-'\' in the head of the line */
        {
            ++p;
        }
    }

    // Construct answer string.
    stack* tmp;
    char *pre;
    char d[16384] = {0};
    char *ans = malloc(16384);
    memset(ans, 0, sizeof(ans));
    ans[0] = '/';
    if (this_dir == NULL)
    {
        return ans;
    }
    for (tmp = this_dir; tmp != NULL; tmp = tmp->next)
    {
        pre = tmp->dir;
        sprintf(d, "%s/%s", pre, ans + 1);
        memcpy(ans + 1, d, strlen(d) + 1);
    }
    len = strlen(ans);
    ans[len-1] = '\0';

    return ans;

}

int main(void) {
    
    char a[] = "/.";
    char *b = simplifyPath(a);
    printf("%s\n", b);
    return 1;
}

    
    



