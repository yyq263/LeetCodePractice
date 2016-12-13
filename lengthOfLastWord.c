#include<string.h>
#include<stdlib.h>
#include<stdio.h>

int lengthOfLastWord(char* s) {
    int length = strlen(s);
    int i = length - 1;
    int ans = 0;
    
    if (length == 0)
        return ans;
    
    while(i >= 0)
    {
        if (s[i] == ' ')
        {
            i--;
        }
        else
            break;
    }
    
    if (i < 0)
        return ans;
    
    while(i >= 0)
    {
        if (s[i] != ' ')
        {
            ans++;
            i--;
        }
        else
            break;
    }

    return ans;
}

int main(void) {
    int ans = lengthOfLastWord("             b d  ");
    printf("ans=%d\n", ans);
}
