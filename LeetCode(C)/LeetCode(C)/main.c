//
//  main.c
//  LeetCode(C)
//
//  Created by 贾辰 on 2018/12/21.
//  Copyright © 2018年 贾辰. All rights reserved.
//

#include <stdio.h>
#include "Primary/Primary_Array.h"

int try(char** board, int boardSize, int* boardColSize) {
    int i, j, r, c, row[9], col[9], martix[9];
    for (i = 0; i < boardSize; i++) {
      memset(row, 0, sizeof(row));
      memset(col, 0, sizeof(col));
      memset(martix, 0, sizeof(martix));
      for (j = 0; j < boardColSize[i]; j++) {
        // 行
        if (board[i][j] != '.') {
          if (row[board[i][j] - '1'] == 1) return 0;
          row[board[i][j] - '1']++;
        }
        // 列
        if (board[j][i] != '.') {
          if (col[board[j][i] - '1'] == 1) return 0;
          col[board[j][i] - '1']++;
        }
        // 九宫格
        r = 3 * (i / 3) + j / 3;
        c = (i % 3) * 3 + j % 3;
        if (board[r][c] != '.') {
          if (martix[board[r][c] - '1'] == 1) return 0;
          martix[board[r][c] - '1']++;
        }
      }
    }
    return 1;
}

void testValidSudoku(void) {
//    int a[2][2] = {1,1,1,1};
    /** 有效的数独*/
    char board[9][9] = {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    
//    char board[9][9] = {{'.'},};
    for (int i = 0; i<9; i++) {
        for (int j = 0; j<9; j++) {
            printf("%c",board[i][j]);
        }
        printf("\n");
    }
//    board[0][0] = '5';
//    board[0][1] = '3';
//    board[0][4] = '7';
//    board[1][0] = '6';
//    board[1][3] = '1';
//    board[1][4] = '9';
//    board[1][5] = '5';
//    board[2][1] = '9';
//    board[2][2] = '8';
//    board[2][7] = '6';
//    board[3][0] = '8';
//    board[3][4] = '6';
//    board[3][8] = '3';
//    board[4][0] = '4';
//    board[4][3] = '8';
//    board[4][5] = '3';
//    board[4][8] = '1';
//    board[5][1] = '7';
//    board[5][4] = '2';
//    board[5][8] = '6';
//    board[6][1] = '6';
//    board[6][6] = '2';
//    board[6][7] = '8';
//    board[7][3] = '4';
//    board[7][4] = '1';
//    board[7][5] = '9';
//    board[7][5] = '9';
//    board[8][4] = '8';
//    board[8][7] = '7';
//    board[8][8] = '9';
    
    int colSize[9] = {9};
    
//    isValidSudoku(board, 9, colSize);
    try(board, 9, &colSize);
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
    
    testValidSudoku();
}


#pragma mark - main
int main(int argc, const char * argv[]) {

    testPrimary();
    
    return 0;
}
