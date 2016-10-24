#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define MAX (int)0x7FFFFFFF
#define MIN (int)0x80000000

bool isPalindrome(int x) {
    long long y = 0;
    int tmpx = x;
    
    if ( tmpx < 0 ) return false;

    while ( tmpx != 0 )
    {
        y = y * 10 + tmpx % 10;
        //printf("x = %d, y = %lld\n", tmpx, y);
        tmpx = tmpx / 10;
    }

    if (y > MAX || y < MIN)
        return false;

    if ((int)y == x)
        return true;
    else
        return false;
}

int main(void) {
    int x = 1;
    bool y;

    y = isPalindrome(x);
    printf("y = %d\n", y);

}
