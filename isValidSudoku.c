#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

static const int rowValidationIndex[81] = {
    0, 1, 2, 3, 4, 5, 6, 7, 8,
    9, 10, 11, 12, 13, 14, 15, 16, 17,
    18, 19, 20, 21, 22, 23, 24, 25, 26,
    27, 28, 29, 30, 31, 32, 33, 34, 35,
    36, 37, 38, 39, 40, 41, 42, 43, 44,
    45, 46, 47, 48, 49, 50, 51, 52, 53,
    54, 55, 56, 57, 58, 59, 60, 61, 62,
    63, 64, 65, 66, 67, 68, 69, 70, 71,
    72, 73, 74, 75, 76, 77, 78, 79, 80
};

static const int columsValidationIndex[81] = {
    0, 9, 18, 27, 36, 45, 54, 63, 72,
    1, 10, 19, 28, 37, 46, 55, 64, 73,
    2, 11, 20, 29, 38 ,47, 56, 65, 74,
    3, 12, 21, 30, 39, 48, 57, 66, 75,
    4, 13, 22, 31, 40, 49, 58, 67, 76,
    5, 14, 23, 32, 41, 50, 59, 68, 77,
    6, 15, 24, 33, 42, 51, 60, 69, 78,
    7, 16, 25, 34, 43, 52, 61, 70, 79,
    8, 17, 26, 35, 44, 53, 62, 71, 80
};
    
static const int blockValidationIndex[81] = {
    0, 1, 2, 9, 10, 11, 18, 19, 20,
    3, 4, 5, 12, 13, 14, 21, 22, 23,
    6, 7, 8, 15, 16, 17, 24, 25, 26,
    27, 28, 29, 36, 37, 38, 45, 46, 47,
    30, 31, 32, 39, 40, 41, 48, 49, 50,
    33, 34, 35, 42, 43, 44, 51, 52, 53,
    54, 55, 56, 63, 64, 65, 72, 73, 74,
    57, 58, 59, 66, 67, 68, 75, 76, 77,
    60, 61, 62, 69, 70, 71, 78, 79, 80
};


bool checkValid(char* board, const int* index, int length)
{
    int i = 0;
    int valid[9] = {0};


    for (i = 0; i < length; i++)
    {
        printf("board[%d]=%c\n", i, board[index[i]]);
        if(board[index[i]] == '.')
            continue;
        else if(valid[board[index[i]] - '1'] == 0)
        {
            valid[board[index[i]] - '1'] = 1;
        }
        else if(valid[board[index[i]] - '1'] == 1)
        {
            return false;
        }
    }
    return true;

}

bool isValidSudoku(char** board, int boardRowSize, int boardColSize) {
    int i, j;
    char boardPlain[82] = {0};

    if(boardRowSize != 9 || boardColSize != 9)
    {
        return false;
    }

    for (i = 0; i < boardRowSize; i++)
    {
        for (j = 0; j < boardColSize; j++)
        {
            boardPlain[9 * i + j] = board[i][j];
        }
    }
    boardPlain[81]='\0';
    //memcpy(boardPlain, board, 81);

    for (i = 0; i < 81; i += 9)
    {
        if (!checkValid(boardPlain, &rowValidationIndex[i], 9) || !checkValid(boardPlain, &columsValidationIndex[i], 9) || !checkValid(boardPlain, &blockValidationIndex[i], 9)){
            printf("1\n");
            return false;
        }
    }
    
    return true;
    
    
}

int main(void) {
    char s[9][9] = {".87654321","2........","3........","4........","5........","6........","7........","8........","9........"};
    int boardRowSize = 9;
    int boardColSize = 9;
    bool ans = isValidSudoku(s, boardRowSize, boardColSize);

    printf("ans=%d\n", ans);

}








    
