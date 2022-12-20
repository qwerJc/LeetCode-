//
//  QuickSort.h
//  LeetCode(C)
//
//  Created by 贾辰 on 2022/11/28.
//  Copyright © 2022 贾辰. All rights reserved.
//

#ifndef QuickSort_h
#define QuickSort_h

#include <stdio.h>
#include <vector>

class QuickSort {
public:
    // 快排
    void quick_sort(std::vector<int>& vec, int start, int end);
    int quick_sort_partition(std::vector<int>& vec, int start, int end);
private:
    void swap(std::vector<int>& vec, int index1, int index2);
}
#endif /* QuickSort_h */
