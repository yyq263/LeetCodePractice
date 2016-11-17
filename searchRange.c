#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void findTargetIndex(int *s,int *ans, int m, int target, int beg, int end) {
    int i = m-1, j = m+1;
    ans[0] = m; // init: very important
    ans[1] = m;
    while (i >= beg)
    {
        if(s[i] == target)
        {
            ans[0] = i;
            i--;
        }
        else
        {
     
            break;
        }
    }
    while (j <= end)
    {
        if(s[j] == target)
        {
            ans[1] = j;
            j++;
        }
        else
        {
            break;
        }
    }

}

void binarySearch(int *s, int *ans, int beg, int end, int target) {

    if(beg <= end)
    {
        int m = (beg + end) / 2;
        
        if(s[m] == target) 
            findTargetIndex(s, ans, m, target, beg, end);
        else if (s[m] > target)
            binarySearch(s, ans, beg, m - 1, target);
        else
            binarySearch(s, ans, m + 1, end, target);
    }
}
    

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    
    int *ans = (int*)malloc(sizeof(int) * 2);
    int beg = 0;
    int end = numsSize - 1;
    ans[0] = -1;
    ans[1] = -1;
    *returnSize = 2;
    
    if (numsSize == 0)
        return ans;

    binarySearch(nums, ans, beg, end, target);

    return ans;
}


int main(void) {
    int s[] = {1,1,1,1,1,2};
    int len = sizeof(s) / sizeof(int);
    int target = 3;
    int *ans;
    int returnSize;

    ans = searchRange(s, len, target, &returnSize);
    printf("ans = [%d, %d]\n", ans[0], ans[1]);        
    

}
