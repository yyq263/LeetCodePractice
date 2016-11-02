#include<stdio.h>
#include<stdlib.h>


#define ABS_W32(a)   (((int32_t)a >= 0) ? ((int32_t)a) : -((int32_t)a))

int cmpInt ( const void *a , const void *b )
{
    return *(int *)a - *(int *)b;
}

int findTwoSumClosest(int* nums, int numsSize, int target) {
    
    int i = 0, j = numsSize - 1;
    int ans = nums[0] + nums[1]; 

    printf("numsSize = %d, target=%d\n", numsSize, target);
    while (i < j) {
        if (nums[i] + nums[j] == target) {
            ans = nums[i] + nums[j];
            //printf(" %d\n", ans);
            return ans;
        }
        else if (nums[i] + nums[j] > target) {
            //printf("i=%d, j=%d,  %d\n",i, j, ans);
            ans = ABS_W32(ans - target) < (nums[i] + nums[j] - target) ? ans : nums[i] + nums[j];
            j--;
        }
        else { //nums[i] + nums[j] < target
            ans = ABS_W32(target - ans) < (target - nums[i] - nums[j]) ? ans : nums[i] + nums[j];
            //printf("i=%d, j=%d, %d\n", i, j, ans);
            i++;
        }
    }
    //printf(" %d\n", ans);
    return ans;
}

int threeSumClosest(int* nums, int numsSize, int target) {

    int i;
    int ansCandidate = 0;

    if (numsSize == 0)
    {
        return 0;
    }

    int ans = nums[0] + nums[1] + nums[2];

    qsort(nums, numsSize, sizeof(int), cmpInt);

    for (i = 0; i < numsSize - 2; i++) {

        ansCandidate = findTwoSumClosest(&nums[i + 1], numsSize - i - 1, target - nums[i]);
        //printf("answerCandidate = %d\n", ansCandidate);
        ans = ABS_W32(ans - target) < ABS_W32(ansCandidate + nums[i] - target) ? ans : (ansCandidate + nums[i]);
        //printf("answer = %d\n", ans);
        

    }

    return ans;
}

int main(void){
    
    int input[] = {0,2,1,-3};
    int target = 1;
    int inputSize = sizeof(input) / sizeof(int);
    int returnSize;
    int i;
    int answer;

    answer = threeSumClosest(input, inputSize, target);
    
    printf("answer = %d\n", answer);
}
