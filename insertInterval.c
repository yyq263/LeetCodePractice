#include<stdlib.h>
#include<stdio.h>
#include<string.h>

//Definition for an interval.
struct Interval {
    int start;
    int end;
};
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct Interval* insert(struct Interval* intervals, int intervalsSize, struct Interval newInterval, int* returnSize) {
    int i, j;
    struct Interval* answer = (struct Interval*)malloc(1000*sizeof(struct Interval));
    int start = newInterval.start;
    int end = newInterval.end;
    j = 0;

    if (intervalsSize == 0)
    {
        answer[0].start = newInterval.start;
        answer[0].end = newInterval.end;
        *returnSize = 1;
        return answer;
    }

    
    // Insert start
    for (i = 0; i < intervalsSize; i++)
    {
        if (start < intervals[i].start)
        {
            //printf("start: %d, interval start: %d\n", start, intervals[i].start);
            answer[j].start = start;
            break;
        }
        // start >= intervals[i].start
        else if (start <= intervals[i].end)
        {
            //printf("i: %d, j = %d, start: %d, interval end: %d\n", i,j , start, intervals[i].end);
            answer[j].start = intervals[i].start;
            break;
        }
        // start > intervals[i].end, store the interval 
        else
        {
            memcpy(&answer[j], &intervals[i], sizeof(struct Interval));
            j++;
        }
        // Next interval
    }
    if (start > intervals[intervalsSize - 1].end)
    {
        answer[j].start = start;
    }

    // Insert end
    for (; i < intervalsSize; i++)
    {

        if (end < intervals[i].start)
        {
            //printf("end: %d, interval start: %d\n", end, intervals[i].start);            
            answer[j].end = end;
            j++;
            break;
        }
        // end >= intervals[i].start
        else if (end <= intervals[i].end)
        {
            //printf("j = %d, end: %d, interval end: %d\n",j, end, intervals[i].end);
            answer[j].end = intervals[i].end;
            i++;
            j++;
            break;
        }

    }

    // if end > end of the interval, this is the last answer.
    if (end > intervals[intervalsSize - 1].end)
    {
        answer[j].end = end;
        j++;
    }
        
    for(;i < intervalsSize; j++, i++)
    {
        memcpy(&answer[j], &intervals[i], sizeof(struct Interval));
    }
    *returnSize = j;
    return answer;
}

int main(void) {
    struct Interval* s = (struct Interval *)malloc(4 * sizeof(struct Interval));
    s[0].start = 1; s[0].end = 2;
    s[1].start = 4; s[1].end = 6;
    s[2].start = 8; s[2].end = 10;
    s[3].start = 15; s[3].end = 18;
    struct Interval p;
    p.start = 4;
    p.end = 9;
    int returnSize = 0;
    int i;
    struct Interval *ans = insert(s, 3, p, &returnSize);

    printf("returnSize = %d\n", returnSize);
    for (i = 0; i < returnSize; i++)
    {
        printf("[%d, %d], ", ans[i].start, ans[i].end);
    }
    printf("\n");
    
}
    
