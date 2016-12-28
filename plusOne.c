#include<stdlib.h>
#include<stdio.h>
#include<string.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {

    if (digitsSize == 0)
    {
        return NULL;
    }

    int ansTmp[digitsSize];
    int *ans;
    int i;
    int C = 0;
    
    ansTmp[digitsSize - 1] = (1 + digits[digitsSize - 1] + C) % 10; 
    C = (1 + digits[digitsSize - 1] + C) >= 10 ? 1 : 0;
    printf("%d -> %d\n", digits[digitsSize - 1], ansTmp[digitsSize - 1]);
    
    for (i = digitsSize - 2; i >= 0; i--)
    {
        ansTmp[i] = (digits[i] + C) % 10; 
        C = (digits[i] + C) >= 10 ? 1 : 0;
        printf("%d -> %d, C=%d\n", digits[i], ansTmp[i], C);
    }
    if (C == 1)
    {
        ans = (int*)malloc((digitsSize + 1) * sizeof(int));
        ans[0] = 1;
        memcpy(ans + 1, ansTmp, digitsSize * sizeof(int));
        *returnSize = digitsSize + 1;
    }
    else
    {
        ans = (int*)malloc(digitsSize * sizeof(int));
        memcpy(ans, ansTmp, digitsSize * sizeof(int));
        *returnSize = digitsSize;
    }
    return ans;
}

int main(void) {
    int digits[5] = {9,9,9,9,91};
    int returnSize = 0;
    int *ans = plusOne(digits, 5, &returnSize);
    int i;
    for (i = 0; i < returnSize; i++)
    {
        printf("%d", ans[i]);
    }
    printf("\n");
}
    
