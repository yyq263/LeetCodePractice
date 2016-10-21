#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX (int)0x7FFFFFFF
#define MIN (int)0x80000000
int reverse(int x) {
    
    long long y = 0;
    int right = 0;

    while (x != 0)
    {
        //printf("x = %d, y = %d \n", x, y);
        y = y * 10 + x % 10;
        x /= 10;

    }


    if (y > MAX || y < MIN)
        return 0;
    else
        return (int)y;
    
}

int main(void)
{
    int x = -2100004477;
    int y = reverse(x);
    //printf("x = %d, y = %d \n", x, y);


}    
