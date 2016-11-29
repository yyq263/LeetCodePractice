#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int trap(int* height, int heightSize) {
    
    int i = 0, max = 0, top = 0;
    int ans = 0, start;

    if (heightSize <= 2)
        return 0;
    
    for (i = 0; i < heightSize; i++)
    {
        if (height[i] > max)
        {
            max = height[i];
            top = i;
        }
    }

    start = height[0];
    for ( i = 0; i < top; i++ )
    {
        if (start < height[i])
            start = height[i];
        else
            ans += (start - height[i]);
    }

    start = height[heightSize - 1];
    for ( i = heightSize - 1; i > top; i-- )
    {
        if (start < height[i])
            start = height[i];
        else
            ans += (start - height[i]);
    }
    
    return ans;
}

int main(void) {
    int s[] = {5, 1, 10, 3, 6};
    int size = sizeof(s) / sizeof(int);
    int ans = trap(s, size);
    printf("ans = %d\n", ans);

}
    


