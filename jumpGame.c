#include<stdlib.h>
#include<stdio.h>

bool canJump(int* nums, int numsSize) {
    int reach = 0;
    int i;
    for(i = 0; i < numsSize && i <= reach; i++)
    {
        reach = reach > (i+nums[i]) ? reach : (i+nums[i])
    }
    return (i == numsSize);
    
}
