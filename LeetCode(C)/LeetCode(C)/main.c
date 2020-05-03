//
//  main.c
//  LeetCode(C)
//
//  Created by 贾辰 on 2018/12/21.
//  Copyright © 2018年 贾辰. All rights reserved.
//

#include <stdio.h>
#include "Primary/Primary_Array.h"

int try(char** board, int boardSize, int* boardColSize);

void testValidSudoku(void) {
    char board[10][10] = {{'9','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    
    char  **s ;
    s = (char **) malloc(sizeof(char**));
    for (int i = 0; i<9; i++) {
        *(s+i) =  board[i];
    }
    
    for (int i1 = 0; i1<9; i1++) {
        for (int j1 = 0; j1<9; j1++) {
            printf(" %c ",s[i1][j1]);
        }
        printf("\n\n");
    }
    
    int colSize[] = {9,9,9,9,9,9,9,9,9};
    
    isValidSudoku(s, 9, colSize);
}

// 函数声明
void testPrimary(void) {
//    int arr1[3] = {4,9,5};
//    int arr2[5] = {9,4,9,8,4};
//    int arr3[5] = {9,4,9,9,9};
//    int arr4[6] = {9,9,9,9,9,9};
//    int *returnArr;

/** 加1 */
//    int arrLength;
//    returnArr = plusOne(arr4, 6, &arrLength);
//    printIntArrWithoutLineBreak(returnArr, arrLength);
    
/** 移动0 */
//    int arrZero1[5] = {0,1,0,3,12};
//    int arrZero2[1] = {0};
//    int arrZero[15] = {0,5,0,1,0,0,0,0,3,7,0,0,12,0,0};
//    moveZeroes(arr2, 5);
//    printIntArrWithoutLineBreak(arrZero1, 5);
    
    // 有效的数独
//    testValidSudoku();
    
//    int input[3][3] = {7,4,1,8,5,2,9,6,3};
    int input[3][3] = {1,2,3,4,5,6,7,8,9};
    int lenght[3] = {3,3,3};
    int **in = (int**)malloc(sizeof(int**));
    for (int i = 0; i<3; i++) {
        in[i] = input[i];
    }
    rotate(in, 3, lenght);
}


#pragma mark - main
int main(int argc, const char * argv[]) {

    testPrimary();
    
    return 0;
}
