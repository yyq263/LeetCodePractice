#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int getFactorial(int n) {

    int i;
    int s = 1;

    for (i = 2; i <= n; i++)
    {
        s *= i;
    }
    return s;
}
    

char* getPermutation(int n, int k) {
    int s[n];
    int i, j;
    char *ans = (char*)malloc(n + 1);
    int p;
    int index;
    int f;

    if(k <= 0)
    {
        return NULL;
    }
    
    for (i = 0; i < n + 1; i++)
    {
        s[i] = i + 1;
    }

    p = n - 1;
    k--;
    
    for (i = 0; i < n; i++)
    {
        f = getFactorial(p - i);
        printf("f=%d, ", f);
        index = k / f;
        printf("index=%d, ", index);
        ans[i] = s[index] + '0';
        
        for (j = index; j < n - i -1; j++)
        {
            s[j] = s[j + 1];
        }
        k = k % f;
        printf("\n");
    }
    ans[n] = '\0';
    return ans;
}

int main(void) {
    int n = 4;
    int k = 18;
    char *ans = getPermutation(n, k);
    int i;
    
    printf("ans=%s\n", ans);
}
    
