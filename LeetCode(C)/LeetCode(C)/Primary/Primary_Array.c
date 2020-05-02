//
//  Primary_Array.c
//  LeetCode(C)
//
//  Created by 贾辰 on 2020/4/3.
//  Copyright © 2020 贾辰. All rights reserved.
//

#include "Primary_Array.h"


void printIntArr(int *arr, int arrSize) {
    for (int i =0; i<arrSize; i++) {
        printf("  %d  \n",arr[i]);
    }
}

void printIntArrWithoutLineBreak(int *arr, int arrSize) {
    for (int i =0; i<arrSize; i++) {
        printf(" %d ",arr[i]);
    }
    printf("\n");
}

int intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int res = 0;
    for (int i = 0; i < nums1Size; i++) {
        res = res ^ nums1[i];
        printf("%d : %d\n",nums1[i], res);
    }
    return 1;
}

#pragma mark - 加一
/**
 动态数组多一位，判断如果进位长度等于原长度，则整体进1
*/
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int length = 0;
    *returnSize = digitsSize;
    int *arrResult = (int*)malloc(sizeof(int)*(digitsSize+1));
    for (int i = digitsSize-1; i>=0; i--) {
        if (digits[i] == 9) {
            length++;
        } else {
            break;
        }
    }
    
    // 整体进1
    if (length == digitsSize) {
        *returnSize = (digitsSize+1);
        arrResult[0] = 1;
        for (int i =1; i<=length; i++) {
            arrResult[i] = 0;
        }
    } else if (length > 0) {
        // 局部进1
        arrResult = digits;
        for (int i = 1; i<=length; i++) {
            arrResult[digitsSize -i] = 0;
        }
        arrResult[digitsSize-length -1] = arrResult[digitsSize-length -1]+1;
    } else {
        // 末位累加
        arrResult = digits;
        arrResult[digitsSize-1] += 1;
    }
    
    return arrResult;
}

#pragma mark - 移动0
/**
 双指针，一个指0，一个指非0，两个交换
 */
void moveZeroes(int* nums, int numsSize) {
    
    int left = 0;
    int unZeroIndex = 0;
    for (unZeroIndex =0 ; unZeroIndex< numsSize; unZeroIndex++) {
        if (nums[unZeroIndex] != 0 ) {
            /** 注意: 这里必须要交换，否则输入【1，2】这样不含0的数组会有问题*/
            int temp = nums[left];
            nums[left] = nums[unZeroIndex];
            nums[unZeroIndex] = temp;
            
            left ++;
        }
        printIntArrWithoutLineBreak(nums,numsSize);
    }
}

#pragma mark - 两数之和
/**
    hash
*/
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    // 创建hash
    return 0;
}

#pragma mark - 有效的数独

int isValidSudoku(char** board, int boardSize, int *boardColSize) {
    
    // 一维数组9代表9行，二维数组做hash用
    int rowHash[9][9] = {0};
    int colHash[9][9] = {0};
    int sBox[9][9] = {0};
    
    for (int i = 0; i<boardSize; i++) {
        for (int j = 0; j< boardColSize[i]; j++) {
            if(board[i][j] == '.') {
                continue;
            } else {
                int index = board[i][j] - '1';
                
                // 判断 行row
                if (rowHash[i][index] == 0) {
                    rowHash[i][index] = 1;
                } else {
                    return 0;
                }
                
                // 判断列 col
                if (colHash[j][index] == 0) {
                    colHash[j][index] = 1;
                } else {
                    return 0;
                }
                
                int inexSBox = i/3 + j/3;
                // 判断3x3
                if (sBox[inexSBox][index]==0) {
                    sBox[inexSBox][index] = 1;
                } else {
                    return 0;
                }
            }
        }
    }
    return 1;
}

