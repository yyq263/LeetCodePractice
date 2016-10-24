#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX (int)0x7FFFFFFF
#define MIN (int)0x80000000

int myAtoi(char* str) {
    char *tmp = str;
    long long y = 0;
    int positive = 1; // +: positive = 1; -: positive = 0, '+' or '-' should be converted!
    

        while (*tmp == ' ' || *tmp == '\t')
            tmp++;

        if (*tmp == '-')
        {
            positive = 0;
            tmp++;
        } else if (*tmp == '+') // allow only one '+' or '-'!!!
        {
            tmp++;
        }
        
        while (*tmp >= '0' && *tmp <= '9')
        {
            //printf("tmp=%c\n", *tmp);
            if (positive)
                y = y * 10 + (int)(*tmp - '0');
            else
                y = y * 10 - (int)(*tmp - '0');
            if (y > MAX)
                return MAX;
            if (y < MIN)
                return MIN;
            tmp++;
            if (*tmp == '\0') break;
        }
        return y;
}

int main(void) {
    char x[] = "-+a2378901";
    int y = 0;

    y = myAtoi(x);
    printf("y=%d\n", y);
        
}
