#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int lengthOfLongestSubstring(char* s) {

	int i = 0;
	int length = strlen(s);
	int s_hash[26] = {0};
	int beg = 0, end = 0;
	int ans = 1;


	while (beg < length && end < length)
	{
		if (s_hash[s[end] - 'a'] <= 1)
		{
			end++;
			s_hash[s[end] - 'a'] += 1;
			ans = ans > (end - beg + 1) ? ans : (end - beg + 1);
		}
		else
		{
			s_hash[s[end] - 'a'] = 0;
			beg++;
		}
	}
	return ans;
}
