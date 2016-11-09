#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int removeDuplicates(int* nums, int numsSize) {
    int i = 0, j = i + 1;

    if (numsSize == 0)
        return 0;
    
    while(j < numsSize) //two pointers, i is trying to chase j
    {
        if (nums[j] > nums[i])
        {
            nums[i + 1] = nums[j];
            i++; j++;
        } else {
            j++;
        }
    }
    return i + 1;
}

int main(void) {
    int a[] = {0};
    int len = sizeof(a) / sizeof(int);
    int b = removeDuplicates(a, len);
    int i = 0;
    for (i = 0; i < b;i++)
    {
        printf("%d, ", a[i]);
    }
    printf("\n");
}
