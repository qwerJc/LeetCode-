//
//  Primary_Array.c
//  LeetCode(C)
//
//  Created by 贾辰 on 2020/4/3.
//  Copyright © 2020 贾辰. All rights reserved.
//

#include "Primary_Array.h"
#include <stdlib.h>

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

#pragma mark  删除排序数组中的重复项
/**
 双指针法：
    如果右指针指向的值等于左指针指向的值，左指针不动。
    如果右指针指向的值不等于左指针指向的值，那么左指针往右移一步，然后再把右指针指向的值赋给左指针
*/
int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) {
        return 0;
    }
    
    int left = 0;
    int right = 1;
    for (; right<numsSize;) {
        if (nums[left] == nums[right]) {
            right++;
        } else {
            left++;
            nums[left] = nums[right];
        }
    }

    return left+1;
}

#pragma mark  买卖股票最佳时机
/**
    注意 判断峰值时候的 要带上=的条件，以解决连续多个相同数字时无法判断出连续的问题
*/
int maxProfit(int* prices, int pricesSize) {
    int sum = 0;
    int low_value = prices[0];
    for (int i = 1; i<pricesSize-1; i++) {
        int last_value = prices[i-1];
        int cur_value = prices[i];
        int next_value = prices[i+1];
        
        // low
        if (last_value >= cur_value && cur_value <= next_value) {
            low_value = cur_value;
        }
        
        // top
        if (last_value <= cur_value && cur_value >= next_value) {
            sum += cur_value - low_value;
            low_value = next_value;
        }
    }
    
    if (prices[pricesSize-1] > low_value) {
        sum += prices[pricesSize-1] - low_value;
    }
    
    return sum;
}

#pragma mark - 加一
/**
 动态数组多一位，判断如果进位长度等于原长度，则整体进1
*/
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int length = 0;
    *returnSize = digitsSize;
    int *arrResult = malloc(sizeof(int)*(digitsSize+1));
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

#pragma mark - 移动0（给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序）
/**
 双指针，一个指0，一个指非0，两个交换
 */
void moveZeroes(int* nums, int numsSize) {
    
    int left = 0;
    int unZeroIndex = 0;
    for (unZeroIndex =0 ; unZeroIndex< numsSize; unZeroIndex++) {
        // 这里通过循环来确定非0指针
        // left指针不一定指向的都是0，如果遇到非0的数字，这样项关于arr【1】和arr【1】交换，没有影响
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
    
    // rowHash数组的每一个item为对应位置元素的按位与
    int rowHash[9] = {0};
    int colHash[9] = {0};
    int sBox[9] = {0};
    
    for (int i = 0; i<boardSize; i++) {
        for (int j = 0; j< boardColSize[i]; j++) {
            if(board[i][j] == '.') {
                continue;
            } else {
                int diff = board[i][j] - '1';
                int value = (1<<diff);
                // 判断 行row
                if (rowHash[i]&value) {
                    return 0;
                } else {
                    rowHash[i] = rowHash[i] | value;
                }
                
                // 判断列 col
                if (colHash[j]&value) {
                    return 0;
                } else {
                    colHash[j] = colHash[j] | value;
                }
                
                int inexSBox = 3*(i/3) + j/3;
                // 判断3x3
                if (sBox[inexSBox]&value) {
                    return 0;
                } else {
                    sBox[inexSBox] = sBox[inexSBox] | value;
                }
            }
        }
    }
    return 1;
}

#pragma mark - 旋转图像
// Tips：
//      1、先转置，再横向翻转
//      2、旋转4个矩形
void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    for (int i = 0; i< matrixSize; i++) {
        for (int j = 0 ; j<matrixColSize[i]; j++) {
            printf(" %d ",matrix[i][j]);
        }
        printf("\n");
    }
    
    printf("-------- \n");
    
    int centerX = matrixSize/2; // 这样就不用判断奇偶了（matrixSize%2==0? matrixSize/2 : matrixSize/2-1）
    int centerY = (matrixSize+1)/2;
    
    for (int i = 0; i< centerX; i++) {
        for (int j = 0 ; j< centerY; j++) {
            
            int temp = matrix[i][j];
            
            // 以下遵循 （x,y）-> (n-y-1,x);
            matrix[i][j] = matrix[matrixSize-j-1][i];
            
            matrix[matrixSize-j-1][i] = matrix[matrixSize-i-1][matrixSize-j-1];
            
            matrix[matrixSize-i-1][matrixSize-j-1] = matrix[j][matrixSize-i-1];
            
            matrix[j][matrixSize-i-1] = temp;
            
        }
    }
    
    for (int i = 0; i< matrixSize; i++) {
        for (int j = 0 ; j<matrixColSize[i]; j++) {
            printf(" %d ",matrix[i][j]);
        }
        printf("\n");
    }
}
