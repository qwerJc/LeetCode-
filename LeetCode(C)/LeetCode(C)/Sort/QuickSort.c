//
//  QuickSort.c
//  LeetCode(C)
//
//  Created by 贾辰 on 2022/11/28.
//  Copyright © 2022 贾辰. All rights reserved.
//

#include "QuickSort.h"
void swap(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}
void quick_sort_recursive(int arr[], int start, int end) {
    if (start >= end)
        return;
    int mid = arr[end];
    int left = start, right = end - 1;
    while (left < right) {
        // 找到一个左侧大于 枢纽的
        while (arr[left] < mid && left < right)
            left++;
        
        // 在右侧找到一个小于枢纽的
        while (arr[right] >= mid && left < right)
            right--;
        
        // 两着交换
        swap(&arr[left], &arr[right]);
    }
    if (arr[left] >= arr[end])
        swap(&arr[left], &arr[end]);
    else
        left++;
    
    // 此时 left处于中间位置，作为枢纽
    
    // 遍历左侧
    if (left) {
        quick_sort_recursive(arr, start, left - 1);
    }
    
    // 遍历右侧
    quick_sort_recursive(arr, left + 1, end);
}
void quick_sort(int arr[], int len) {
    quick_sort_recursive(arr, 0, len - 1);
}

//void swap_quick(int *arr,int i, int j) {
//    int temp = arr[i];
//    arr[i]=arr[j];
//    arr[j]=temp;
//}
//
//void quick_sort_recursive(int arr[],int start,int end) {
//    if (start<end) {
//        int pivot = quick_partition(arr,start,end);
//
//        quick_sort_recursive(arr, start, pivot-1);
//        quick_sort_recursive(arr, pivot+1, end);
//    }
//}
//
//int quick_partition(int arr[], int start, int end) {
//    int mid = arr[start]; // 以子表的第一位作为枢纽
//    while (start<end) {
//
//        // 从后往前找到比枢纽小的换到左边
//        while (start<end && arr[end]>=mid) {
//            end--;
//        }
//        // 找到了一个比枢纽小的数，交换
//        swap_quick(arr, start, end);
//
//        while (start<end && arr[start]<=mid) {
//            start++;
//        }
//        // 找到了一个左边比枢纽大的数，交换
//        swap_quick(arr, start, end);
//    }
//    此时 start 作为枢纽
//    return start;
//}
