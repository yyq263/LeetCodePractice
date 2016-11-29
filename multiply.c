#include<string.h>
#include<stdlib.h>
#include<stdio.h>


char* multiplyChar(char* A, char b, int zeroAppend) { // length of b is 1
    int c = 0, i;
    int lenA = strlen(A);
    int tmp = 0;
    char myans[lenA + 1];
    int ansLen = 0;
    char* ans;

    myans[lenA] = '\0';
    for (i = lenA - 1; i >= 0; i--)
    {
        tmp = (A[i] - '0') * (b - '0') + c;
        c = tmp / 10;
        myans[i] = (char)('0' + tmp % 10);
    }

    if ( c != 0)
    {
        ansLen = 1 + zeroAppend + lenA;
        ans = (char*)malloc(ansLen + 1);
        memset(ans, 0, ansLen);
        ans[0] = (char)('0' + c);
        for (i = 0; i < lenA; i++)
        {
            ans[i+1] = myans[i];
        }
        for (i = lenA; i < lenA + zeroAppend; i++)
        {
            ans[i+1] = '0';
        }
    }
    else
    {
        ansLen = zeroAppend + lenA;
        ans = (char*)malloc(ansLen + 1);
        memset(ans, 0, ansLen);
        for (i = 0; i < lenA; i++)
        {
            ans[i] = myans[i];
        }
        for (i = lenA; i < lenA + zeroAppend; i++)
        {
            ans[i] = '0';
        }
    }
    ans[ansLen] = '\0';
    return ans;
}

char* addString(char* num1, char* num2) // num2 needs to be invalidated.
{
    
    if (num1 == NULL)
        return num2;
    
    int c = 0, i, j, k;
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int lenAnsTmp = len1 > len2 ? len1 : len2; // may be lenAnsTmp + 1;
    int tmp = 0;
    char myans[lenAnsTmp + 1]; 
    char *ans;
    int ansLen;

    myans[lenAnsTmp] = '\0';
    i = len1 - 1; // num1
    j = len2 - 1; // num2
    k = lenAnsTmp - 1; // myans
    while (i >= 0 && j >= 0)
    {
        tmp = (num1[i] - '0') + (num2[j] - '0') + c;
        c = tmp / 10;
        myans[k] = (char)('0' + tmp % 10);
        k--;i--;j--;
    }
    while (i >= 0)
    {
        tmp = num1[i] - '0' + c;
        c = tmp / 10;
        myans[k] = (char)('0' + tmp % 10);
        i--;k--;
    }
    while (j >= 0)
    {
        tmp = num2[j] - '0' + c;
        c = tmp / 10;
        myans[k] = (char)('0' + tmp % 10);
        k--;j--;
    }
    if(num1)
    {
        free(num1);
        num1 = NULL;
    }
    if(num2)
    {
        free(num2);
        num2 = NULL;
    }


    if (c == 1)
    {
        ansLen = 1 + lenAnsTmp ;
        ans = (char*)malloc(ansLen + 1);
        ans[0] = '1';
        strcpy(&ans[1], myans);
    }
    else
    {
        ansLen = lenAnsTmp;
        ans = (char*)malloc(ansLen + 1);
        strcpy(ans, myans);
    }
        
    ans[ansLen] = '\0';
    return ans;
    
}

char* multiply(char* num1, char* num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    char *ans = NULL;
    int i, appendZero = 0;
    
    if (len1 == 0 || len2 == 0)
        return NULL;
    for (i = len2 - 1; i >= 0; i--)
    {
        ans = addString(ans, multiplyChar(num1, num2[i], appendZero));
        
        appendZero += 1;
    }
    i = 0;
    while (ans[i] == '0')
    {
        i++;
    }
    if (i >= strlen(ans))
        return "0";
    
    return &ans[i];
}
    

int main(void) {
    char a[] = "99222222";
    char b[] = "1";
    char *c = multiply(a, b);

    printf("ans=%s\n", c);
}
