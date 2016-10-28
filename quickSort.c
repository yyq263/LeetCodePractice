#include<stdlib.h>
#include<stdio.h>

#define min(x, y) (x < y ? x : y)

void myswap(int*s, int index_a, int index_b) {
    int tmp = s[index_a];
    s[index_a] = s[index_b];
    s[index_b] = tmp;
    return ;
}
    

void quickSort(int* s, int arraySize) {

    int i = 1, j = arraySize - 1; // first and last index
    int r = s[0];
        
    if (arraySize < 2)
    {
        return; // not update array
    }

    while (j > i) {

        while (j > i)
        {
            if (s[j] < r)
                break;
            else
                j--;
        }

        while (j > i)
        {
            if (s[i] > r)
                break;
            else
                i++;
        }
        printf("i = %d, j = %d\n",i, j);
        if (i == j) {
            if (i == 1 && s[i] > r) { // r is minimum ignore r and continue.
                quickSort(&s[1], arraySize - 1);
            }else
                myswap(s, 0, i);
        }
        else 
            myswap(s, i, j);
    }

    quickSort(&s[0], i);
    quickSort(&s[i + 1], arraySize - i - 1);

    return;
}


int main(void) {
    int x[] = {2, 3, 4, 1111,2,31,  11,11,1110, 100, 8};
    int len = 11;
    int i;
    
    quickSort(x, len);

    for (i = 0; i < len; i++)
        printf("%d, ", x[i]);
    printf("\n");
}
