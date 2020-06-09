//
//  SelectSort.c
//  LeetCode(C)
//
//  Created by 贾辰 on 2020/6/7.
//  Copyright © 2020 贾辰. All rights reserved.
//

#include "SelectSort.h"
// 时间复杂度 O(n2)

void swap(int *arr,int i, int j) {
    int temp = arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}
    
void SelectSort(int* arr, int arraySize) {
    int i,j,min;
    for (i = 0; i<arraySize; i++) {
        min = i;
        for (j = i+1; j<arraySize; j++) {
            if (arr[min]>arr[j]) {
                min = j;
            }
        }
        // 如果min！=i，说明交换过
        if (min!=i) {
            swap(arr, min, i);
        }
    }
}
