//
//  main.c
//  LeetCode(C)
//
//  Created by 贾辰 on 2018/12/21.
//  Copyright © 2018年 贾辰. All rights reserved.
//

#include <stdio.h>
#include "Primary/Primary_Array.h"
#include "Primary_String.h"

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
    
}


// 函数声明
void testPrimaryArray(void) {
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
    
//    testValidSudoku();
    
}

void testString(void) {
    /** 反转字符串 */
//    char s[6] = {'H','a','n','n','a','h'};
//    reverseString(s, 6);
    
    /** 整数反转 */
//    reverse(123);
//    reverse(-123);
//    reverse(120);
//    reverse(1534236469);
    
    /** 字符串中唯一字符 */
    char *s = "leetcode";
    firstUniqChar(s);
}

#pragma mark - main
int main(int argc, const char * argv[]) {
//    testPrimaryArray();
    
    testString();

    return 0;
}
