//
//  BubbleSort.c
//  LeetCode(C)
//
//  Created by 贾辰 on 2020/6/7.
//  Copyright © 2020 贾辰. All rights reserved.
//

#include "BubbleSort.h"
// 时间复杂度 O(n2)


void swap(int *arr,int i, int j) {
    int temp = arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

#pragma mark - 最简单冒泡排序（其实属于选择排序）
// 缺点：
//    这样排序一轮后，除了目标数据到了指定位置，对于其他数据没有帮助
void BubbleSort0(int* nums, int numsSize) {
    int i,j;
    for (i = 0 ; i<numsSize; i++) {
        for (j=i+1; j<numsSize; j++) {
            if (nums[i]>nums[j]) {
                swap(nums, i, j);
            }
        }
    }
}

#pragma mark - 正统冒泡排序
// 改进：这样排序一轮后，目标数据到了指定位置，其余数据也会相应移动
void BubbleSort1(int* nums, int numsSize) {
    int i,j;
    for (i = 0 ; i<numsSize; i++) {
        for (j=i+1; j<numsSize-1; j++) {
            // ⚠️：改进的地方
            if (nums[j]>nums[j+1]) {
                swap(nums, j, j+1);
            }
        }
    }
}

#pragma mark - 冒泡排序（优化）
// 改进：如果某轮排序后，列表已经有序，其实可以用flag来记一下，不再需要比较
void BubbleSort2(int* nums, int numsSize) {
    int i,j;
    for (i = 0 ; i<numsSize; i++) {
        // ⚠️：改进的地方
        int flag = 0;// flag为1时证明当前已经有序，退出循环
        
        for (j=i+1; j<numsSize-1; j++) {
            if (nums[j]>nums[j+1]) {
                swap(nums, j, j+1);
                flag = 1;
            }
        }
        
        if (flag==0) {
            break;
        }
    }
}
