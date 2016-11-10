#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int strStr(char* haystack, char* needle) {

    int i = 0;
    int lenHaystack = strlen(haystack);
    int lenNeedle = strlen(needle);
    
    if (lenNeedle == 0)
        return 0;
    
    if (lenHaystack == 0)
        return -1;

    while (i < lenHaystack)
    {
        if (strlen(&haystack[i]) < lenNeedle )
            break;
        if (haystack[i] == needle[0])
        {
            if (strncmp(&haystack[i], needle, lenNeedle) == 0)
                return i;
        }
        
        i++;
    }
    return -1;
}


int main(void) {
    char a[] = "abcdabcabc";
    char b[] = "abca";
    int ans = strStr(a, b);

    printf("%s, %s, ans = %d\n", a, b, ans);
    
}
