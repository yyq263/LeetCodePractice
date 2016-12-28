#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* addBinary(char* a, char* b) {
    int len_a = strlen(a) ;
    int len_b = strlen(b) ;
    int ansLen = len_a > len_b ? len_a : len_b;
    int ansTmp[ansLen];
    char *ans;
    int C=0;
    int i = ansLen - 1;
    
    if (len_a == 0 || len_b == 0)
    {
        ans = "0";
        return ans;
    }
    
    while(len_a - 1 >= 0 && len_b - 1>= 0)
    {
        ansTmp[i] = (a[len_a - 1] - '0' + b[len_b - 1] - '0'+ C) % 2;
        C = (a[len_a - 1] - '0' + b[len_b - 1] - '0' + C) >= 2 ? 1 : 0;
        //printf("%d, C = %d\n", ansTmp[i], C);
        len_a--;
        len_b--;
        i--;
    }
    //printf("lena = %d, lenb = %d\n", len_a, len_b);
    if (len_a - 1 >= 0)
    {
        for (i = len_a - 1; i >= 0; i--)
        {
            ansTmp[i] = (C + a[i] - '0') % 2;
            C = (C + a[i] - '0') >= 2 ? 1 : 0;
            //printf("%d, C = %d\n", ansTmp[i], C);
        }
    }
    else if (len_b - 1 >= 0)
    {
        for (i = len_b - 1; i >= 0; i--)
        {
            ansTmp[i] = (C + b[i] - '0') % 2;
            C = (C + b[i] - '0') >= 2 ? 1 : 0;
        }
    }

    //printf("C=%d\n", C);
    if (C == 1)
    {
        ans = (char*)malloc(ansLen + 2);
        ans[0] = '1';
        for (i = 1; i < ansLen + 1; i++)
        {
            ans[i] = '0' + ansTmp[i - 1];
            //printf("%c\n", ans[i]);
        }
        ans[ansLen + 1] = '\0';

    }
    else
    {
        ans = (char*)malloc(ansLen + 1);
        for (i = 0; i < ansLen; i++)
        {
            ans[i] = '0' + ansTmp[i];
            //printf("%c\n", ans[i]);
        }
        ans[ansLen] = '\0';
    }
    return ans;
}

int main(void) {
    char *a = "0";
    char *b = "0";
    char *ans = addBinary(a, b);
    printf("%s + %s = %s\n",a,b, ans);
}
