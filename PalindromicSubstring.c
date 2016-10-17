#include<stdlib.h>
#include<string.h>
#include<stdio.h>

int longestPalindrome(char* s)
{
    int length = strlen(s);
    int beg = 0, end = length - 1;
    int b = 0, e = 0;
    int ans;
    

    for (beg = 1; beg < length; beg++)
    {
        b = beg--; e = beg++;
        while (b >= 0 && e < length)
        {
            if (s[b] == s[e])
            {
                ans = ans > (e - b + 1) ? ans : (e - b + 1);
                b++; e--;
            }
        }
    }    
}


int main(void)
{
    char input[] = "abcc";
    int beg = 0;
    int end = strlen(input) - 1;
    
    longestPalindrome(input);

    
    //printf("ret= %d\n", ret);
}
