//
//  DynamicProgram.h
//  LeetCode(C)
//
//  Created by 贾辰 on 2022/12/25.
//  Copyright © 2022 贾辰. All rights reserved.
//

#ifndef DynamicProgram_h
#define DynamicProgram_h

#include <stdio.h>

class Solution {
public:
    // BM64 最小花费爬楼梯
/**
 * 给定一个整数数组 cost  ，其中 cost[i]  是从楼梯第i个台阶向上爬需要支付的费用，下标从0开始。一旦你支付此费用，即可选择向上爬一个或者两个台阶。
    你可以选择从下标为 0 或下标为 1 的台阶开始爬楼梯。
*/
// 思路：整理状态转移方程：dp中记录的为实际花费，需要用之前的台阶+当前花费，因此
//        dp[0] = 0
//        dp[1] = 0
//        dp[2] = min(dp[0] + cost[0], dp[1]+cost[1]);
//        dp[3] = min(dp[2] + cost[2], dp[1]+cost[1]);

    int minCostClimbingStairs(std::vector<int>& cost) {
        // write code here
        std::vector<int> dp;
        dp.push_back(0);
        dp.push_back(0);

        for (int i = 2; i<=cost.size(); i++) {
            int value_i2 = dp[i-2] + cost[i-2];
            int value_i1 = dp[i-1] + cost[i-1];
            dp.push_back(std::min(value_i1, value_i2));
        }

        return dp.back();
    }
    
    // BM65 最长公共子序列(二)
};


#endif /* DynamicProgram_h */
