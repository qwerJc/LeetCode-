//
//  MergeSort.hpp
//  LeetCode(C)
//
//  Created by 贾辰 on 2022/12/20.
//  Copyright © 2022 贾辰. All rights reserved.
//

#ifndef MergeSort_hpp
#define MergeSort_hpp

#include <stdio.h>
#include <vector>

class MergeSort {
public:
    // 归并排序
    void merge_sort(std::vector<int>& vec, int left, int right);
    void merge_sort_merge(std::vector<int>& vec,int left,int mid,int right);

}

#endif /* MergeSort_hpp */
