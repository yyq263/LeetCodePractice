#include<stdio.h>
#include<stdlib.h>

int minPathSum(int** grid, int gridRowSize, int gridColSize) {
    if (gridRowSize == 0 || gridColSize == 0)
    {
        return 0;
    }
    /* // Special cases */
    /* if (gridRowSize == 1) */
    /* { */
    /*     return grid[0][gridColSize - 1]; */
    /* } */
    /* if (gridColSize == 1) */
    /* { */
    /*     return grid[gridRowSize - 1][0]; */
    /* } */

    int i, j;
    int row[gridColSize];
    // Init answer row
    for (i = 0; i < gridColSize; i++)
    {
        row[i] = grid[0][i];
    }
    
    // First row
    for (i = 1; i < gridColSize; i++)
    {
        row[i] += row[i - 1];
        printf("row[%d] = %d\n", i, row[i]);            
    }
    // Next rows...
    for (j = 1; j < gridRowSize; j++)
    {
        row[0] += grid[j][0];
        for (i = 1; i < gridColSize; i++)
        {
            row[i] = (row[i - 1] < row[i] ? row[i - 1] : row[i]) + grid[j][i];
            printf("row[%d] = %d\n", i, row[i]);            
        }
    }
    
    return row[gridColSize - 1];
}

int main(void) {
    int *s[3];
    int s1[5] = {1,2,3,4,5};
    int s2[5] = {7,1,8,9,2};
    int s3[5] = {3,1,4,5,7};
    s[0] = s1;
    s[1] = s2;
    s[2] = s3;

    int ans = minPathSum(s, 3, 5);
    printf("ans = %d\n", ans);
}

