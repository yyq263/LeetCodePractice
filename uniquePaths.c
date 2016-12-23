#include<stdio.h>
#include<stdlib.h>

int uniquePaths(int m, int n) {
    if (n == 0 || m == 0)
        return 0;
    if (m == 1)
        return 1;
    if (m == 2)
        return n;
    int i,j;
    int row[n];
    // m >= 3
    for (i = 0; i < n; i++)
    {
        row[i] = i + 1;
    }
        
    for (i = 3; i <= m; i++ )
    {
        for (j = 1; j < n; j++)
        {
            row[j] += row[j - 1];
            printf("row[%d] = %d\n", j, row[j]);
        }
    }
    return row[n-1];
}

int main(void){
    int m = 1, n = 10;
    printf("answer = %d\n", uniquePaths(m, n));
}

