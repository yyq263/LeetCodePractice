#include<stdlib.h>
#include<stdio.h>
#include<string.h>

void binarySearch(int *s, int *ans, int beg, int end, int target) {

    if(beg <= end)
    {
        int m = (beg + end) / 2;
        
        if(s[m] == target) 
            *ans = m;
        else if (s[m] > target)
        {
            if (m - 1 >= beg && s[m - 1] < target)
                *ans = m;
            else if (m - 1 < beg)
                *ans = m;
            else
                binarySearch(s, ans, beg, m - 1, target);
        }
        else // s[m] < target
            if (m + 1 <= end && s[m + 1] > target)
                *ans = m + 1;
            else if (m + 1 > end)
                *ans = m + 1;
            else
                binarySearch(s, ans, m + 1, end, target);
    }
}

int searchInsert(int* nums, int numsSize, int target) {

    int beg = 0;
    int end = numsSize - 1;
    int ans = -1;

    if (numsSize = 0)
        return 0;
    
    binarySearch(nums, &ans, beg, end, target);
    return ans;
}

int main(void) {

    int s[] = {1,88};
    int len = sizeof(s) / sizeof(int);
    int target = 0;
    int ans;

    ans = searchInsert(s, len, target);
    printf("ans = %d\n", ans);
}

