#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/* // A Recursive Way */
/* void helper(int* count, int target, int* sum) { */
/*     int step; */

/*     if (*sum == target) */
/*     { */
/*         (*count)++; */
/*         return; */
/*     } */

/*     if (*sum > target) */
/*     { */
/*         return; */
/*     } */
    
/*     for (step = 1; step <= 2; step++) */
/*     { */
/*         if (*sum < target) */
/*         { */
/*             *sum += step; */
/*             helper(count, target, sum); */
/*             *sum -= step; */
/*         } */
/*     } */
/* } */

/* int climbStairs(int n) { */
/*     int count = 0; */
/*     int sum = 0; */

/*     if (n == 0) */
/*     { */
/*         return 0; */
/*     } */
/*     helper(&count,n, &sum); */
/*     return count; */
/* } */

// Fibonacci
int climbStairs(int n)
{
    if (n < 4) return n;
    int a = 2, b = 3, c = 5;
    int i;
    for (i = 5; i <= n; i++)
    {
        a = c;
        c = b+c;
        b = a;
    }
    return c;
}

int main(void) {
    printf("answer = %d\n", climbStairs(38));
}
