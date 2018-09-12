//
//  sort.swift
//  LeetCode
//
//  Created by 贾辰 on 2018/8/13.
//  Copyright © 2018年 贾辰. All rights reserved.
//

import Foundation

class Sort{
    
    func test(array:inout [Int]) {
        print(array)
        insertSort2(array: &array)
        print(array)
    }
    
    /// 冒泡排序：
    //    比较相邻的元素，如果前一个比后一个大，就把它们两个调换位置。
    //    对每一对相邻元素作同样的工作，从开始第一对到结尾的最后一对。这步做完后，最后的元素会是最大的数。
    //    针对所有的元素重复以上的步骤，除了最后一个。
    //    持续每次对越来越少的元素重复上面的步骤，直到没有任何一对数字需要比较
    //******************************************************************
    // 分类 -------------- 内部比较排序
    // 数据结构 ---------- 数组
    // 最差时间复杂度 ---- O(n^2)
    // 最优时间复杂度 ---- 如果能在内部循环第一次运行时,使用一个旗标来表示有无需要交换的可能,可以把最优时间复杂度降低到O(n)
    // 平均时间复杂度 ---- O(n^2)
    // 所需辅助空间 ------ O(1)
    // 稳定性 ------------ 稳定
    func bubbleSort(array:inout [Int]) -> Void {
        for index in (0...array.count-1).reversed(){
            var i = 0;
            while(i < index){
                if (array[i] > array[i+1]){
                     array[i...(i+1)].reverse()
                }
                i = i + 1
            }
        }
    }
    
    /// 选择排序：
    //  初始时在序列中找到最小（大）元素，放到序列的起始位置作为已排序序列；
    //  然后，再从剩余未排序元素中继续寻找最小（大）元素，放到已排序序列的末尾。
    //  以此类推，直到所有元素均排序完毕。
    //******************************************************************
    // 分类 -------------- 内部比较排序
    // 数据结构 ---------- 数组
    // 最差时间复杂度 ---- O(n^2)
    // 最优时间复杂度 ---- O(n^2)
    // 平均时间复杂度 ---- O(n^2)
    // 所需辅助空间 ------ O(1)
    // 稳定性 ------------ 不稳定
    func selectSort(array:inout [Int]) -> Void {
        for i in 0..<array.count{
            var min = i
            for j in i+1..<array.count {
                if array[min] > array[j] {
                    min = j
                }
            }
            if min != i{
                array.swapAt(i, min)
            }
        }
    }
    
    /// 插入排序：
    //    从第一个元素开始，该元素可以认为已经被排序
    //    取出下一个元素，在已经排序的元素序列中从后向前扫描
    //    如果该元素（已排序）大于新元素，将该元素移到下一位置
    //    重复步骤3，直到找到已排序的元素小于或者等于新元素的位置
    //    将新元素插入到该位置后
    //    重复步骤2~5
    //******************************************************************
    // 分类 ------------- 内部比较排序
    // 数据结构 ---------- 数组
    // 最差时间复杂度 ---- 最坏情况为输入序列是降序排列的,此时时间复杂度O(n^2)
    // 最优时间复杂度 ---- 最好情况为输入序列是升序排列的,此时时间复杂度O(n)
    // 平均时间复杂度 ---- O(n^2)
    // 所需辅助空间 ------ O(1)
    // 稳定性 ------------ 稳定
    func insertSort(array:inout [Int]) {
        for i in 1..<array.count {
            for j in (0..<i){
                /* 此处 array[i] <= array[j] 则为不稳定 */
                if (array[i] < array[j]) {
                    array.insert(array[i], at: j)
                    array.remove(at: i+1)
                    break;
                }
            }
        }
    }
    
    func insertSort2(array:inout [Int]){
        for i in 1..<array.count{
            let get = array[i]
            for j in (0..<i).reversed(){
                if (array[j] > array[i]){
                    array.swapAt(j+1, j)
                }
                array[j+1] = get
            }
        }
    }
    
    func try1(array:inout [xcValue]){
        for i in 1..<array.count { // you
            for j in 0..<i{ // zuo
                if array[i].id <= array[j].id {
                    array.insert(array[i], at: j)
                    array.remove(at: i+1)

                    break;
                }
            }
        }
    }
    func try2(array:inout [xcValue]){
        for index in (0...array.count-1).reversed(){
            var i = 0;
            while(i < index){
                if (array[i].id > array[i+1].id){
                    array[i...(i+1)].reverse()
                }
                i = i + 1
            }
        }
    }
    
    func try3(array:inout [xcValue]){
        for i in 1..<array.count{
//            log(array: array)
            let get = array[i]
            var j = i - 1
            while (j>=0 && array[j].id>get.id){
                array[j+1] = array[j]
                j = j - 1
            }
            array[j+1] = get
        }
        log(array: array)
    }
    
    func try33(array:inout [xcValue]){
        for i in 1..<array.count{
//            log(array: array)
            let get = array[i]
            var j = i-1
            while j>=0 {
                if (array[j].id > array[i].id){
                    array[j+1] = array[j]
                    j = j - 1
                }else{
                    break;
                }
            }
            array[j+1] = get
        }
        log(array: array)
    }
    
    func log(array:[xcValue]){
        var str = ""
        for index in array{
            str.append(String(index.id))
            str.append(" ")
        }
        print(str)
    }
}
