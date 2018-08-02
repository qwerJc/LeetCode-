//
//  ArrayTest.swift
//  LeetCode
//
//  Created by 贾辰 on 2018/7/27.
//  Copyright © 2018年 贾辰. All rights reserved.
//

import Foundation

class ArrayPractice {
    
    //**************************【26. 删除排序数组中的重复项】(68.82%)**************************
    
    private func removeDuplicates(nums:inout [Int]) -> Int {
        
        var index = nums.count - 1;
        
        while index > 0 {
            if nums[index] == nums[index-1]{
                nums.remove(at: index)
            }
            index = index-1
        }
        
        return nums.count;
    }
    
    func testRemoveDuplicates() -> Void {
        var inputArr2 = [0,0,1,1,1,1,1,2,2,3,3,4]
        let result = self.removeDuplicates(nums: &inputArr2)
        print(result)
        
    }
    
    //**************************【买卖股票的最佳时机2】(18.79%)**************************
    func buyAndSellStockChance(prices: [Int]) -> Int {
        var minValue:Int? = nil
        var maxValue:Int? = nil
        var sum = 0
        
        for (index,item) in prices.enumerated() {
            
            if (minValue == nil && maxValue == nil){
                minValue = prices[index]
                maxValue = prices[index]
                continue
            }else{
                if item < minValue! {
                    minValue = item
                    maxValue = item
                }else if item >= maxValue! {
                    maxValue = item
                    if (index+1) == prices.count{
                        print("峰值(i:" + String(index) + ")：" + String(maxValue!) + "-" + String(minValue!))
                        sum += maxValue! - minValue!
                        minValue = nil
                        maxValue = nil
                    }else if (prices[index+1] < maxValue!){
                        print("峰值(i:" + String(index) + ")：" + String(maxValue!) + "-" + String(minValue!))
                        sum += maxValue! - minValue!
                        minValue = nil
                        maxValue = nil
                    }
                }
            }
        }
        return sum
    }
    
    func testBuyAndSellStockChance() -> Void {
        let result = buyAndSellStockChance(prices: [5,2,3,2,6,6,2,9,1,0,7,4,5,0])
        print(result)
    }
    
    private func rotateArray(_ nums: inout [Int], _ k: Int) {
        
    }
}
