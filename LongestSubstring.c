#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int lengthOfLongestSubstring(char* s) {

	int i = 0;
	int length = strlen(s);
	int s_hash[256] = {0}; // expand to all ascii characters
	int beg = 0, end = 0;
	int ans = 0;

        s_hash[(int)s[beg]] += 1;
        
	while (beg < length && end < length)
	{
            printf("beg=%d, end=%d\n", beg, end);
            if (s_hash[(int)s[end]] <= 1)
            {
                ans = ans > (end - beg + 1) ? ans : (end - beg + 1);
                end++;
                if (end == length)
                    break;
                else
                {
                    //printf("s[end] = %c\n", s[end] );
                    s_hash[(int)s[end]] += 1;
                }
            }
            else
            {
                s_hash[(int)s[beg]] -= 1;
                beg++;
            }
	}

	return ans;
}

int main(void)
{
    char input[] = "aaaaaaaa";
    int ans = 0;
    ans = lengthOfLongestSubstring(input);
    printf("ans = %d\n", ans);
}
