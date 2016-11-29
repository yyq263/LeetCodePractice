#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int firstMissingPositive(int* nums, int numsSize) {
    int i, max;
    
    for (i = 0; i < numsSize; i++)
    {
        if (nums[i] > max )
            max = nums[i];
    }

    int s[max + 1];
    memset(s, 0, sizeof(s));

    for (i = 0; i < numsSize; i++)
    {
        if (nums[i] <= 0)
            continue;
        s[nums[i] - 1] += 1;
    }

    /* for ( i = 0; i < max+1; i++) */
    /* { */
    /*     printf("%d, ", s[i]); */
    /* } */
    /* printf("\n"); */
    
    for (i = 0; i < max+1; i++)
    {
        if (s[i] == 0)
            return i+1;
    }
    
    return 1;// Never goes here
}


int main(void) {
    int s[] = {0,1,2,3,4,5};
    int len = sizeof(s) / sizeof(int);

    int ans = firstMissingPositive(s, len);
    printf("ans = %d\n", ans);
    
}
