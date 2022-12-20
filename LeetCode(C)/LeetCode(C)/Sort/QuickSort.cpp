//
//  QuickSort.c
//  LeetCode(C)
//
//  Created by 贾辰 on 2022/11/28.
//  Copyright © 2022 贾辰. All rights reserved.
//

#include "QuickSort.h"
void QuickSort::swap(std::vector<int>& vec, int index1, int index2) {
    int tem = vec[index1];
    vec[index1] = vec[index2];
    vec[index2] = tem;
}

void QuickSort::quick_sort(std::vector<int>& vec, int start, int end) {
    if (start >= end) {
        return;
    }
    int key = quick_sort_partition(vec, start, end);
    quick_sort(vec,start, key-1);
    quick_sort(vec, key+1, end);
}

int QuickSort::quick_sort_partition(std::vector<int>& vec,int start, int end) {
    int left = start;
    int right = end;
    int pivot = vec[start];
    
    
    while (left < right) {
        // right指针从右向左进行比较
        while (left <right && vec[right]>pivot) {
            right--;
        }
        
        // left指针从左往右,这里注意要等于，以处理掉最开始left = start的情况
        while (left < right && vec[left]<=pivot) {
            left++;
        }
        
        // left与right没有相遇，则交换
        //找到left比基准大，right比基准小，进行交换
        if (left < right) {
            swap(vec, left, right);
        }

    }
    // left与right相遇，将基准与left交换
    swap(vec, start, left);
    return left;
}
