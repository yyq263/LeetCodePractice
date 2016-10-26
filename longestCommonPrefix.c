#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define GET_MIN(A, B)        (A < B ? A : B)  // Get min value
#define GET_MAX(A, B)        (A > B ? A : B)  // Get max value

char* longestCommonPrefix(char** strs, int strsSize) {

    char *answer;  
    int i, j;

    if (strsSize == 0)
    {
        *answer = '\0';
        return answer;
    }
    
    int commonLen = strlen(strs[0]);
    answer = (char *)malloc(commonLen + 1);
    memset(answer, 0, sizeof(answer));

    strncpy(answer, strs[0], commonLen + 1);
    
    for (i = 1; i < strsSize; i++)
    {
        j = 0;
        while( j < GET_MIN(strlen(strs[i]), commonLen))
        {
            if (strs[i][j] == answer[j])
                j++;
            else
                break;
        }
        commonLen = GET_MIN(j, commonLen);
        //printf("commonLen = %d\n", commonLen);
        answer[commonLen] = '\0'; // The position after last word
        if (commonLen == 0)
            break;
    }
    return answer;

}

int main(void) {

    char *input[3];
    int strSize = 1;
    char *output;

    input[0] = "";
    //input[1] = "daabcec";
    //input[2] = "aaabca";
    output = longestCommonPrefix(input, strSize);
    
    printf("output = %s\n", output);
}
