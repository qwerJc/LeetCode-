//
//  Dynamicprogramming_Single.c
//  LeetCode(C)
//
//  Created by 贾辰 on 2022/10/30.
//  Copyright © 2022 贾辰. All rights reserved.
//

#include "Dynamicprogramming_Single.h"
#pragma mark  最长上升子序列
/**
    注意 判断峰值时候的 要带上=的条件，以解决连续多个相同数字时无法判断出连续的问题
*/
int getlength(int* nums,int numsSize,int minIndex);
int lengthOfLIS(int* nums, int numsSize){
//    int length = getlength(nums, numsSize-1, <#int minIndex#>)
    return 1;
}
