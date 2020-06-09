//
//  ShellSort.c
//  LeetCode(C)
//
//  Created by 贾辰 on 2020/6/7.
//  Copyright © 2020 贾辰. All rights reserved.
//

#include "ShellSort.h"
// 时间复杂度 O(n2)

void ShellSort(int* arr, int arraySize) {
    int i,j;
    int increment = arraySize;
    
    do {
        increment = increment/3+1;
        
        // 执行插入排序
        for (i = increment; i<arraySize; i++) {
            int temp = arr[i];
            if (arr[i]<arr[i-1]) {
                
                for (j = i-1; arr[j]>arr[i]; j--) {
                    arr[j+1]=arr[j];
                }
                
                arr[j+1] = temp;
            }
        }
        
    } while (increment>1);
}
