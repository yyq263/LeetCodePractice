#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define GET_MIN(A, B)        (A < B ? A : B)  // Get min value
#define GET_MAX(A, B)        (A > B ? A : B)  // Get max value

// Brute way, really brute
/* int maxArea(int* height, int heightSize) { */

/*     int length = 0, h = 0, area = 0; */
/*     int i = 0, j = 0; */

/*     if (heightSize < 2) return 0; */
    
/*     for (i = 0; i < heightSize - 1; i++) // a_1 --> a_n-1 */
/*     { */
/*         for (j = heightSize - 1; j != i; j--) // a_n-1 --> a_(i+1) */
/*         { */
/*             if (h > GET_MIN(height[i], height[j])) */
/*             { */
/*                 continue; */
/*             } */
/*             else */
/*             { */
/*                 h = GET_MIN(height[i], height[j]); */
/*                 length = j - i; */
/*                 area = GET_MAX(length * h, area); */
/*             } */
/*         } */
/*     } */
/*     return area; */

/* } */

// O(n) way for the worst case a_i is 1:n
int maxArea(int* height, int heightSize) {

    int area = 0;
    int tmpArea = 0;
    int i = 0, j = heightSize - 1;
    while (i < j)
    {
        tmpArea = GET_MIN(height[i], height[j]) * (j - i);
        area = area > tmpArea ? area : tmpArea;
        height[i] < height[j] ? i++ : j--;
    }
    return area;
}

int main(void)
{
    int height[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    int heightSize = sizeof(height) / sizeof(int);
    int area = 0;

    area = maxArea(height, heightSize);

    printf("maxArea = %d\n", area);
    
    
}
