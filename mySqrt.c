#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// Binary Search
/* int mySqrt (int n){ */

/*     if (n < 0) */
/*         return n; */
/*     if (n == 1) */
/*         return 1; */
/*     long long  mid; */
/*     long long low = 0, up = n; */
/*     mid = (low + up) / 2; */
/*     do { */
/*         if (mid * mid > n) */
/*             up = mid; */
/*         else if (mid * mid == n) */
/*             return mid; */
/*         else */
/*             low = mid; */
/*         mid = (up + low) / 2; */
/*         printf("up = %lld, low = %lld\n", up, low); */
/*     } */
/*     while ( up - low > 1 ); */

/*     //return ( abs(up * up - n) < abs(low * low - n) ? up : low); */
/*     return (int)low; */
/* } */

// Newton's root finding
int mySqrt(int n) {
    float res = (float)n;
    float eps = 0.01;
    float last;
    
    if (n < 0)
        return n;
    if (n == 0)
        return 0;
    do {
        last = res;
        res = (n / res + res) / 2;
    } while(abs(res - last) > eps);
    printf("res = %.2f\n", res);
    return (int)res;
}

int main(void) {

    int x = 2147395599;
    int y = mySqrt(x);
    printf("y = %d\n", y);
}
