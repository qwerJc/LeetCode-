//
//  InsertSort.c
//  LeetCode(C)
//
//  Created by 贾辰 on 2020/6/7.
//  Copyright © 2020 贾辰. All rights reserved.
//

#include "InsertSort.h"
// 时间复杂度 O(n2)

void insertSort(int* arr, int arraySize) {
    int i,j;
    for (i=2; i<arraySize; i++) {
        
        if (arr[i]<arr[i-1]) {
            // 临时记录遇到的小于已排序的数字
            int temp = arr[i];
            
            // 逆序遍历已排序数据(前n个)，所有元素后移，并寻找当前位置
            for (j = i-1; arr[j]>temp; j--) {
                arr[j+1] = arr[j];
            }
            
            // 将当前元素插入指定位置
            arr[j] = temp;
        }
    }
}
