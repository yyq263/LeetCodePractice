#include<stdlib.h>
#include<stdio.h>

#define MAX (int)0x7FFFFFFF
#define MIN (int)0x80000000

int divide(int dividend, int divisor) {
    
    long long num = (long long)dividend;
    long long den = (long long)divisor;
    long long ans = 0;
    long long o = 0;
    int div = 0;
    int change_sign = 0;

    if (dividend == 0)
        return 0;

    if (num < 0)
    {
        num = -num;
        change_sign++;
    }

    if (den < 0)
    {
        den = -den;
        change_sign++;
    }

    while(den <= num)
    {

        if ((den<<div <= num) && (den<<(div+1) > num))
        {
            ans = (long long)1 << div; // 2^k
            o += ans; // sum(2^k)
            num -= den * ans;
            //printf("den = %lld, ans = %lld, num = %lld\n", den, ans, num);
            div = 0;
        } else
            div++;

    }

    if (change_sign == 1)
    {
        o = -o;
    }
    if (o > MAX)
        return MAX;
    if (o < MIN)
        return MIN;
    return o;

}

int main(void) {
    int a = 5;
    //int a = 125;
    int b = 2;
    int c = divide(a,b);
    printf("c = %d\n", c);
}
