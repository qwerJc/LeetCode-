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
    
    //**************************【旋转数组】**************************
    // 方法1（13.33%）
    private func rotateArray1(_ nums: inout [Int], _ k: Int) {
        var count:Int
        if k > nums.count {
            count = nums.count - k%nums.count
        }else{
            count = nums.count - k
        }
        while count>0 {
            let item = nums.first!
            nums.removeFirst()
            nums.append(item)
            count = count - 1
        }
    }
    
    // 方法2（22.0%）
    private func rotateArray2(_ nums: inout [Int], _ k: Int) {
        var index:Int
        if k > nums.count {
            index = k % nums.count
        }else{
            index = k
        }
        while index > 0 {
            nums.insert(nums.removeLast(), at: 0)
            index = index - 1
        }
    }
    
    // 方法3（24.67%）
    private func rotateArray3(_ nums: inout [Int], _ k: Int) {
        var moveCount = k % nums.count
        if moveCount > nums.count/2 {
            // 应该左移
            moveCount = nums.count - moveCount
            while moveCount > 0 {
                nums.append( nums.removeFirst())
                moveCount = moveCount - 1
            }
        }else{
            // 正常右移
            while moveCount > 0 {
                nums.insert(nums.removeLast(), at: 0)
                moveCount = moveCount - 1
            }
        }
    }
    
    // 方法4 (66.7%)
    private func rotateArray4(_ nums: inout [Int], _ k: Int) {
        var newArr = [Int]()
        var index:Int
        if k > nums.count {
            index = k % nums.count
        }else{
            index = k
        }
        while index > 0 {
            newArr.append(nums.removeLast())
            index = index - 1
            
        }
        newArr.reverse()
        newArr.append(contentsOf: nums)
        nums = newArr
    }
    
    func testRotateArray() -> Void {
        var arr = [1,2,3,4,5,6,7]
//        rotateArray1(&arr, 3)
//        rotateArray2(&arr, 3)
//        rotateArray3(&arr, 3)
        rotateArray4(&arr, 3)
        print(arr)
    }
}
