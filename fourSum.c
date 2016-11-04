#include<stdio.h>
#include<stdlib.h>

typedef struct list{
    int num[4]; // answer
    struct list *next;
} list;

void insert_list(list **l, int num1, int num2, int num3, int num4) { 
  list *p;
  p = (list*)malloc(sizeof(list));
  p->num[0] = num1;
  p->num[1] = num2;
  p->num[2] = num3;
  p->num[3] = num4;
  // insert to top
  p->next = *l;
  *l = p;
}

int cmpInt ( const void *a , const void *b )
{
    return *(int *)a - *(int *)b;
}

void findTwoSum(int* nums, int numsSize, int target, int p, int q, list** result) {
    
    int i = 0, j = numsSize - 1;
    while (i < j) {

        if (nums[i] + nums[j] < target) {
            i++;
        }
        else if (nums[i] + nums[j] > target) {
            j--;
        }
        else { //nums[i] + nums[j] == target
            //printf(" %d, %d, %d\n", nums[i], nums[j], -target);
            insert_list(result, nums[i], nums[j], p, q);
            i++;
            j--;
            while ( i < j && nums[i] == nums[i - 1]) {
                i++;
            }
            while ( i < j && nums[j] == nums[j + 1]) {
                j--;
            }
        }
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** fourSum(int* nums, int numsSize, int target, int* returnSize) {
    
    int i = 0, j = 0;
    list *ans = NULL;
    list *show = NULL;
    
    *returnSize = 0;
    
    if (numsSize == 0)
        return NULL;

    qsort(nums, numsSize, sizeof(int), cmpInt);

    for (i = 0; i < numsSize - 3; i++) {
        if ( i != 0 && nums[i] == nums[i - 1])
            continue;
        for (j = i + 1; j < numsSize - 2; j++) {
            if (j != i + 1 && nums[j] == nums[j - 1])
                continue;
            findTwoSum(&nums[j + 1], numsSize - j - 1, target - nums[i] - nums[j], nums[i], nums[j], &ans);
        }
    }

    /* for (show = ans; show != NULL; show = show->next){ */
    /*     printf("[%d, %d, %d, %d]\n", show->num[0], show->num[1], show->num[2], show->num[3]); */
    /* } */
    /* Construct the answer */
    for (show = ans; show != NULL; show = show->next) {
        (*returnSize)++;
    }
    if ((*returnSize) == 0) {
        return NULL;
    }
    
    int** answer = (int**)malloc(sizeof(int*) * (*returnSize));
    for (i = 0; i < *returnSize; i++) {
        answer[i] = (int*)malloc(sizeof(int) * 4);
    }

    show = ans;
    for(i = 0; i < *returnSize; i++) {
        answer[i][0] = show->num[0];
        answer[i][1] = show->num[1];
        answer[i][2] = show->num[2];
        answer[i][3] = show->num[3];
        show = show->next;
    }

    return answer;
    
}


int main(void) {
    int input[] = {0, 0, 0, 0, -2, 2};
    int inputSize = sizeof(input) / sizeof(int);
    int target = 0;
    int **answer;
    int returnSize;
    int i;

    answer = fourSum(input, inputSize, target, &returnSize);
    for (i = 0; i < returnSize; i++) {
        printf("[%d, %d, %d, %d]\n", answer[i][0], answer[i][1], answer[i][2], answer[i][3]);
    }

    return 1;

}
