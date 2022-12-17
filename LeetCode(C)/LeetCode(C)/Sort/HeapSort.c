//
//  HeapSort.c
//  LeetCode(C)
//
//  Created by 贾辰 on 2022/11/27.
//  Copyright © 2022 贾辰. All rights reserved.
//

#include "HeapSort.h"


void swap_heap(int *arr,int i, int j) {
    int temp = arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

// arr:待排序数组
// index: 当前堆的父节点
// size：arr中的最大index
void HeapAdjuset(int *arr,int index,int size) {
    int par_index = index;
    int son_index = par_index*2+1; // 2*i+1为左子
   
    while (son_index < size) {
        // 1.确保右子没有超过最大size
        // 2.找到左子和右子 偏大的数
        if (son_index+1 < size && arr[son_index+1] > son_index) {
            son_index++; //更新为右子
        }
        
        // 如果父>两子，则已经有序
        if(arr[par_index] > arr[son_index]) {
            return;
        } else {
            swap_heap(arr,par_index,son_index);
            //继续向下寻找孙节点
            par_index = son_index;
            son_index = par_index*2 + 1;
        }
    }
}

/**
  堆排序（完全二叉树：左子<右子<父）
    核心：1、由一个无序序列构建成一个堆
         2、基于构建的堆，调整元素
 */
void HeapSort(int* arr, int arraySize) {
    // arrSize/2-1 最后一个父节点（完全二叉树的性质）
    // 从最后一个父节点开始往前遍历，构建堆
    for (int i=arraySize/2-1; i>=0; i++) {
        HeapAdjuset(arr,i,arraySize);
    }
    
    // 由于每次构建完后，堆顶一定为最大元素，因此将堆顶与最后一个元素交换，以及来逐渐构建从小到大的升序
    for (int i=arraySize; i>0; i--) {
        // 交换堆顶与当前最后一个元素
        swap_heap(arr, i, 1);
        // 重新调整【1..i-1】为最大堆
        HeapAdjuset(arr, 1, i-1);
    }
}
