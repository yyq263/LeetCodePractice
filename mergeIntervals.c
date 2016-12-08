#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Definition for an interval.
struct Interval {
    int start;
    int end;
};

// Quick sort for structure
int cmp(const void *a,const void *b)
{
    struct Interval *p=(struct Interval*)a;
    struct Interval *q=(struct Interval*)b;
    
    return ((p->start) > (q->start)) ? 1 : -1;
}


/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct Interval* merge(struct Interval* intervals, int intervalsSize, int* returnSize) {
    int i;
    int j;
    struct Interval* result = (struct Interval*)malloc(1000 * sizeof(struct Interval));;

    if (intervalsSize == 0)
    {
        *returnSize = 0;
        return NULL;
    }

    if (intervalsSize == 1)
    {
        *returnSize = 1;
        return intervals;
    }

    // Sort 'start' of intervals
    qsort(intervals, intervalsSize, sizeof(intervals[0]), cmp);
    // Init
    memcpy(&result[0], &intervals[0], sizeof(intervals[0]));
    // Start index of result
    j = 0;
    for (i = 1; i < intervalsSize; i++)
    {
        printf("i = %d, j = %d\n", i, j);
        printf(" = %d, j = %d\n", i, j);
        if (intervals[i].start > result[j].end)
        {
            j++;
            memcpy(&result[j], &intervals[i], sizeof(intervals[0]));

        }
        else if (intervals[i].start == result[j].end)
        {
            result[j].end = intervals[i].end;
        }
        // When intervals[i].start < result[j].end ...
        else
        {
            if (intervals[i].end  > result[j].end )
            {
                result[j].end = intervals[i].end;
            }
        }
    }
    *returnSize = j + 1;
    return result;
}

int main(void) {
    struct Interval* s = (struct Interval *)malloc(4 * sizeof(struct Interval));
    s[0].start = 1; s[0].end = 110;
    s[1].start = 2; s[1].end = 6;
    s[2].start = 8; s[2].end = 1200;    
    s[3].start = 15; s[3].end = 18;
    int returnSize = 0;
    int i;
    struct Interval *ans = merge(s, 4, &returnSize);

    printf("returnSize = %d\n", returnSize);
    for (i = 0; i < returnSize; i++)
    {
        printf("[%d, %d], ", ans[i].start, ans[i].end);
    }
    printf("\n");
    
}
    
