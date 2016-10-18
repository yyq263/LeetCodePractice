#include<stdlib.h>
#include<string.h>
#include<stdio.h>

typedef struct Index{
    int b;
    int e;
}Index;

void findPalindrome(char *s, int length, int beg, int end, Index* index)
{
    
    while (beg >= 0 && end < length)
    {
        //printf("s[%d] = %c, s[%d] = %c\n", beg, s[beg], end, s[end]);
        if (s[beg] == s[end])
        {
            if ((end - beg) > (index->e - index->b))
            {
                index->b = beg;
                index->e = end;
            }
            beg--; end++;
        }
        else
            break;
    }


    
}

/*************/
/*a b c c b a*/
/* ||||||||| */
/* 012345678 */ 
/* We will have (2n - 3) start point, */
/* check the characters around the start point with same distance to it, if s[beg] == s[end], then spread the points by 1.*/
/* record begin and end point which have the longest distance.*/
char* longestPalindrome(char* s)
{
    Index index = {0, 0};
    int length = strlen(s);
    int i, beg, end;
    int checkLen = 2 * length - 3;
    char *answer = NULL;

    for (i = 0; i < checkLen; i++)
    {
        if(i % 2)
        {
            beg = (i - 1) / 2;
            end = (i + 3) / 2;
        }
        else
        {
            beg = i / 2;
            end = i / 2 + 1;
        }
        findPalindrome(s, length, beg, end, &index);
    }
    //printf("b = %d, e = %d\n", index.b, index.e);
    answer = (char*)malloc(index.e - index.b + 2);
    memset(answer, 0, sizeof(answer));
    memcpy(answer, &s[index.b], index.e - index.b + 1);
    return answer;
}


int main(void)
{
    char input[] = "abababababa";
    int beg = 0;
    int end = strlen(input) - 1;
    char *ans = NULL;
    
    ans = longestPalindrome(input);
    printf("answer: %s\n", ans);
    free(ans);
    ans = NULL;
}
