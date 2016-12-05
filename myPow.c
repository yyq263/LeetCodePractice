#include<stdio.h>
#include<stdlib.h>


double myPow(double x, int n) {

    long long nn = (long long)n;
    
    if (nn == 0)
        return 1;
    if (x == 0.0)
        return 0.0;

    double result = 1.0;
    
    if (nn < 0)
    {
        nn = -nn;
        x = 1 / x;
    }

    while(nn > 0)
    {
        if (nn % 2 == 1)
        {
            result *= x;
        }
        nn /= 2;
        x *= x;
    }
    return result;
}


int main(void) {
    double a = myPow(2.0, -2147483648);
    printf("a = %8.2f\n", a);
    
}
