//
//  MergeSort.cpp
//  LeetCode(C)
//
//  Created by 贾辰 on 2022/12/20.
//  Copyright © 2022 贾辰. All rights reserved.
//

#include "MergeSort.hpp"

#pragma mark - 归并
void MergeSort::merge_sort(std::vector<int> &vec, int left, int right) {
    if (left == right) {
        return;
    }
    int mid = (left+right)/2;
    
    merge_sort(vec, left, mid);
    merge_sort(vec, mid+1, right);
    merge_sort_merge(vec, left, mid, right);
}

void MergeSort::merge_sort_merge(std::vector<int> &vec, int left, int mid, int right) {
    int i = left;
    int j = mid+1;
    std::vector<int> vec_temp;
    
    while (i<=mid && j<=right) {
        if (vec[i] <= vec[j]) {
            vec_temp.push_back(vec[i]);
            i++;
        } else {
            // vec[j]更小，进栈
            vec_temp.push_back(vec[j]);
            j++;
        }
    }
    
    // 右序列已经完全入栈
    while (i <= mid) {
        vec_temp.push_back(vec[i]);
        i++;
    }
    
    // 左序列已完全入栈
    while (j <= right) {
        vec_temp.push_back(vec[j]);
        j++;
    }
    
    int t = 0;// 标记vec_temp中的index
    while (left <= right) {
        vec[left] = vec_temp[t];
        t++;
        left++;
    }
}
