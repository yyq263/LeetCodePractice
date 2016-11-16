#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define MIN(x, y) (x < y ? x : y)

void mergeSort(int *s, int *k, int beg, int end) {
    int i, j, m, g, k_index;
    
    if(beg >= end)
        return;

    m = (beg + end) / 2;
    mergeSort(s, k, beg, m); //keep dividing...
    mergeSort(s, k, m+1, end);
    i = beg;
    k_index = i;
    j = m+1;
    printf("beg1 = %d, end1 = %d, beg2 = %d, end2 = %d\n", i, m, j, end);
    while (i <= m && j <= end )
    {
        if (s[i] < s[j])
        {
            k[k_index] = s[i];
            i++;
            k_index++;
        }
        else
        {
            k[k_index] = s[j];
            j++;
            k_index++;
            
        }
    }
    while(i <= m)
    {
        k[k_index] = s[i];
        i++;
        k_index++;
    }
    while(j <= end)
    {
        k[k_index] = s[j];
        j++;
        k_index++;
    }
    for (g = beg; g <= end; g++)
    {
        s[g] = k[g];
    }

}

int main(void) {
    int x[] = {9,8,7,6,5,4,3,2,1,0};
    int len = sizeof(x) / sizeof(int);
    int i;
    int ans[len];
    mergeSort(x, ans, 0, len-1);
    
    for (i = 0; i < len; i++)
        printf("%d, ", ans[i]);
    printf("\n");


}
