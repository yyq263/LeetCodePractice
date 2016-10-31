#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cmpInt ( const void *a , const void *b )
{
    return *(int *)a - *(int *)b;
}

int* twoSum(int* nums, int numsSize, int target)
{
    int *ans;
    int numsSorted[numsSize]; 
    int i = 0, j = numsSize - 1;
    int k = 0;
    ans = (int*)malloc(sizeof(int) * 2);
    memset(ans, 0, sizeof(int) * 2);

    memcpy(numsSorted, nums, sizeof(int) * numsSize);
    qsort(numsSorted, numsSize, sizeof(int), cmpInt);

    while (i < j) {
        //printf("i = %d, j = %d\n", i, j);
        if (numsSorted[i] + numsSorted[j] == target) {
            break;
        } else if(numsSorted[i] + numsSorted[j] > target)
            j--;
        else
            i++;
    }

    for ( k = 0; k < numsSize; k++)
    {
        if(nums[k] == numsSorted[i]){
            ans[0] = k;
            continue;
        }
        if(nums[k] == numsSorted[j]){
            ans[1] = k;
            continue;
        }
    }
    
    if (ans[0] > ans[1]) {
        k = ans[0];
        ans[0] = ans[1];
        ans[1] = k;
    }
        
    
    return ans;
}
    
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/* int* twoSum(int* nums, int numsSize, int target) */
/* { */
/*     int i = 0, j = 0; */
/*     int *ans; */
/*     for (i = 0; i < numsSize; i++) */
/*     { */
/*         for (j = 0; j < numsSize; j++) */
/*         { */
/*             if (i == j) */
/*                 continue; */
/*             else if ((nums[i] + nums[j]) == target) */
/*             { */
/*                 ans = (int*)malloc(sizeof(int) * 2); */
/*                 memset(ans, 0, sizeof(int) * 2); */
/*                 ans[0] = i;ans[1] = j; */
/*                 return ans; */
/*             } */
/*         } */
/*     } */
/*     return NULL; */
/* } */

int main(void)
{
    int nums[] = {2,1,9,4,4,56,90,3};
    int numsSize = sizeof(nums) / sizeof(int);
    int target = 8;
    int *answer;
    int i;
    
    answer = twoSum(nums, numsSize, target);
    //twoSum(nums, numsSize, target);

    printf("answer: %d, %d\n", answer[0], answer[1]);
    /* for (i = 0; i < numsSize; i++) */
    /* { */
    /*     printf("%d, ", nums[i]); */
    /* } */
    /* printf("\n"); */
    
    return 1;

}
