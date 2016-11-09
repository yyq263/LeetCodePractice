#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int removeElement(int* nums, int numsSize, int val) {
    int i = 0, j = 0;
    
    if(numsSize == 0)
        return 0;

    while (j < numsSize)
    {

        if (nums[j] != val)
        {
            nums[i] = nums[j];
            i++; j++;
        }
        else
        {
            j++;
        }
    }
    return i;
}

    

int main(void) {
    int a[] = {1, 1, 2};
    int len = sizeof(a) / sizeof(int);
    int b = removeElement(a, len, 1);
    int i = 0;
    printf("b = %d\n", b);
    for (i = 0; i < b;i++)
    {
        printf("%d, ", a[i]);
    }
    printf("\n");
}
