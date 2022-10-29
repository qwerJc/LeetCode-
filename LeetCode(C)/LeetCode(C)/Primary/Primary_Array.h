//
//  Primary_Array.h
//  LeetCode(C)
//
//  Created by 贾辰 on 2020/4/3.
//  Copyright © 2020 贾辰. All rights reserved.
//

#ifndef Primary_Array_h
#define Primary_Array_h

void printIntArr(int *arr, int arrSize);
void printIntArrWithoutLineBreak(int *arr, int arrSize);

#include <stdio.h>
/** 删除排序数组中的重复项*/
int removeDuplicates(int* nums, int numsSize);

/** 两个数组的交集2*/
int intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize);

/** 加一*/
int* plusOne(int* digits, int digitsSize, int* returnSize);

/** 移动0 */
void moveZeroes(int* nums, int numsSize);

/** 两数之和 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize);

/** 有效的数独 */
int isValidSudoku(char** board, int boardSize, int* boardColSize);

/** 旋转图像 */
void rotate(int** matrix, int matrixSize, int* matrixColSize);
#endif /* Primary_Array_h */
