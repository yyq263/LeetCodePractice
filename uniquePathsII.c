#include<stdio.h>
#include<stdlib.h>

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize) {
    if(obstacleGridRowSize == 0 || obstacleGridColSize == 0)
    {
        return 0;
    }
    if (obstacleGrid[0][0] == 1)
        return 0;
    
    int i, j;
    int row[obstacleGridColSize];
    int colFlag = 0;
    for (i = 0; i < obstacleGridColSize; i++)
    {
        if (obstacleGrid[0][i] == 1)
            break;
    }
    if (obstacleGridRowSize == 1 && i < obstacleGridColSize)
        return 0;
    else if (obstacleGridRowSize == 1 && i >= obstacleGridColSize)
        return 1;
    // First row
    if (i < obstacleGridColSize)
    {
        for (j = 0; j < i; j++)
        {
            row[j] = 1;
        }
        for (j = i; j < obstacleGridColSize; j++)
        {
            row[j] = 0;
        }
    }
    else
    {
        for (j = 0; j < obstacleGridColSize; j++)
        {
            row[j] = 1;
        }
    }
    // Next rows...
    for (i = 1; i < obstacleGridRowSize; i++)
    {
        if (obstacleGrid[i][0] == 1)
        {
            colFlag = 1;
            row[0] = 0;
        }
        for (j = 1; j < obstacleGridColSize; j++)
        {
            if (colFlag == 1)
            {
                row[0] = 0;
            }
            if (obstacleGrid[i][j] == 1)
            {
                row[j] = 0;
                continue;
            }
            row[j] += row[j - 1];
            //printf("row[%d] = %d, ", j, row[j]);
        }
        //printf("\n");
    }
    return row[obstacleGridColSize - 1];
}

int main(void) {
    int *s[4];
    int s1[1] = {0,0,0,1,0,0,0};
    int s2[1] = {0,0,0,0,0,0,0};
    int s3[1] = {0,0,0,0,1,0,0};
    int s4[1] = {0,0,0,0,1,0,0};
    s[0] = s1;
    s[1] = s2;
    s[2] = s3;
    s[3] = s4;
    int ans = uniquePathsWithObstacles(s, 4, 7);
    printf("ans = %d\n", ans);
}
