#include<stdlib.h>
#include<string.h>
#include<stdio.h>


double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {

    // First find kth number in two arrays.
    // Assume k < (m + n) / 2.
    int total = nums1Size + nums2Size;
    int part1, part2;
    double result;

    part1 = getKthNumber(nums1, nums1Size, nums2, nums2Size, total / 2);
    part2 = getKthNumber(nums1, nums1Size, nums2, nums2Size, total / 2 + 1);
    printf("part1 = %d, part2 = %d\n", part1, part2);
    
    if (total % 2)
    {
        result = part2;
    }
    else
    {
        result = ((double)part1 + (double)part2) / 2;
    }

    return result;
}

int getKthNumber(int* a, int a_size, int* b, int b_size, int k)
{
    // always assume a_size <= b_size
    int tmpk_b = k / 2;
    int tmpk_a = 0;
    
    if (a_size > b_size)
        return getKthNumber(b, b_size, a, a_size, k);
    // 0 < a_size <= b_size
    if (a_size == 0)
        return b[k - 1];
    if (k == 1)
    {
        if (a == NULL)
        {
            printf("b[0] = %d\n", b[0]);
            return b[0];
        }
        else if (b == NULL)
        {
            printf("a[0] = %d\n", a[0]);
            return a[0];
        }
        else
            return a[0] < b[0] ? a[0] : b[0];
    }
    // k >= 2
    tmpk_a = tmpk_b < a_size ? tmpk_b : a_size;
    
    if (a[tmpk_a - 1] < b[tmpk_b - 1])
    {
        printf("a_size=%d\n", a_size);
        if (a_size - tmpk_a == 0)
        {
            return getKthNumber(NULL,
                                0,
                                b,
                                b_size,
                                k - tmpk_a); // get rid of the least numbers.
        }
        else
        {
        return getKthNumber(a + sizeof(int) * tmpk_a,
                            a_size - tmpk_a,
                            b,
                            b_size,
                            k - tmpk_a); // get rid of the least numbers.
        }
    }
    else if (a[tmpk_a - 1] > b[tmpk_b - 1])
    {
        if ( b_size - tmpk_b == 0)
        {
            return getKthNumber(a, a_size,
                                NULL,
                                0,
                                k - tmpk_b);
        }
        else
        {
            //printf("tmpk_b=%d\n", tmpk_b);
            //printf("a_size=%d\n", a_size);
            return getKthNumber(a, a_size,
                                b + sizeof(int) * tmpk_b,
                                b_size - tmpk_b,
                                k - tmpk_b);
        }
    }
    else // a[tmpk_a - 1] = b[tmpk_b - 1]
    {
        return a[tmpk_a - 1];
    }
}

int main(void) {
    
    int a[] = {1,3,4};
    int sizeA = sizeof(a) / sizeof(int);
    int b[] = {2};
    int sizeB = sizeof(b) / sizeof(int);
    double ret = 0.0;
    ret = findMedianSortedArrays(a, sizeA, b, sizeB);

    printf("answer: %0.2f\n", ret);

}
        


