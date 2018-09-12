//
//  main.swift
//  LeetCode
//
//  Created by 贾辰 on 2018/7/27.
//  Copyright © 2018年 贾辰. All rights reserved.
//

import Foundation

struct xcValue {
    let id:Int
    let Value:String
}

let testArr  = ArrayPractice()
//testArr.testRemoveDuplicates()
//testArr.testBuyAndSellStockChance()
//testArr.testRotateArray()

let testSort = Sort()
var arr:[Int] = [1,2,3,3,3,2,3,0,3,-2,-1]
var arr1:[Int] = [2,8,1,2,3,0,9,7,4]
var arr2:[Int] = [1,3,5,1,59,0,2,5,3,10,4,8,6]
var arr3:[Int] = [8,8, 5, 2,2,6, 9, 4,-3,-5,0, 7]


var arrXC:[xcValue] = [xcValue(id:8, Value:"前"),
                       xcValue(id:8, Value:"后"),
                       xcValue(id:5, Value:"0"),
                       xcValue(id:2, Value:"前"),
                       xcValue(id:6, Value:"0"),
                       xcValue(id:9, Value:"0"),
                       xcValue(id:3, Value:"0"),
                       xcValue(id:0, Value:"0"),
                       xcValue(id:2, Value:"后")]


//testSort.test(array: &arr)
//
//testSort.test(array: &arr1)
//
//testSort.test(array: &arr2)
//testSort.test(array: &arr3)

//*********************************【稳定性测试】**************************
testSort.try3(array: &arrXC)
for item in arrXC{
    print("\(item.id)" + " & " + "\(item.Value)")
}
print("==================[try 33]==========================")
testSort.try33(array: &arrXC)
for item in arrXC{
    print("\(item.id)" + " & " + "\(item.Value)")
}
