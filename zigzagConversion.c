#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* convert(char* s, int numRows) {
    
    int length = strlen(s);
    char *T = (char*)malloc(length + 1);
    int i = 0, j = 0;
    int dis = 0;
    int next = 0;
    int tmpDis = 0;
    int maxDis = 2*numRows - 2;
    
    memset(T, 0, sizeof(T));
    
    if(length == 1 || numRows == 1) { // output is exactly the input
        T = s;
        T[length] = '\0';
        return T;
    }
    
    for (dis = maxDis; dis >= 0; dis -= 2)
    {
        if (dis == 0)
            tmpDis = maxDis;
        else
            tmpDis = dis;
        
        next = i; 
        while (next < length) // trace the next item in the same row.
        {
            //printf("tmpDis = %d, next = %d\n", tmpDis, next);
            T[j] = s[next]; 
            j++;
            next += tmpDis;
            if (tmpDis < maxDis)
                tmpDis = maxDis - tmpDis;
        }
        i++; // next row
    }
    
    T[length] = '\0';
    
    return T;
}

int main(void){
    char input[] = "12345678901234567890";
    int numRows = 20;
    char *output = NULL;

    output = convert(input, numRows);

    printf("output=%s\n", output);
    
}
