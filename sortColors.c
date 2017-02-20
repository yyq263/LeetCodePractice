#include<stdlib.h>
#include<string.h>
#include<stdio.h>

void swap(int* x, int index_a, int index_b) {
    int tmp = x[index_a];
    x[index_a] = x[index_b];
    x[index_b] = tmp;
}

void sortColors(int* nums, int numsSize) {
    int beg = 0;
    int end = numsSize - 1;
    int cur = beg;
    if (numsSize == 0)
        return;
    while(cur <= end)
    {
        //printf("cur=%d, beg=%d, end=%d\n",cur, beg, end);
        if(nums[cur] == 0)
        {
            swap(nums, beg, cur);
            ++beg;
            ++cur;
        }else if( nums[cur] == 2)
        {
            swap(nums, end, cur);
            --end;
        }else // nums[cur] == 1
        {
            cur++;
        }
    }
}

int main(void) {
    int a[] = {0,0,1,2,0,1,0,0,1,2,0,0,2};
    int i;
    int len = sizeof(a)/sizeof(int);
    sortColors(a, len);
    for (i = 0; i < len; i++)
    {
        printf("%d, ", a[i]);
    }
    printf("\n");
}
