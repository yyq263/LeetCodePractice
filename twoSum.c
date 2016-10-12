#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target)
{
    int i = 0, j = 0;
    int *ans;
    for (i = 0; i < numsSize; i++)
    {
        for (j = 0; j < numsSize; j++)
        {
            if (i == j)
                continue;
            else if ((nums[i] + nums[j]) == target)
            {
                ans = (int*)malloc(sizeof(int) * 2);
                memset(ans, 0, sizeof(int) * 2);
                ans[0] = i;ans[1] = j;
                return ans;
            }
        }
    }
    return NULL;
}

int main(void)
{
    int nums[] = {4, 7, 2, 11, 23, 22};
    int numsSize = sizeof(nums) / sizeof(int);
    int target = 9;
    int *answer;
    
    answer = twoSum(nums, numsSize, target);

    printf("answer: %d, %d\n", answer[0], answer[1]);
    
    return 1;

}
