//
//  Primary_String.c
//  LeetCode(C)
//
//  Created by 贾辰 on 2020/5/2.
//  Copyright © 2020 贾辰. All rights reserved.
//

#include "Primary_String.h"
#include <limits.h>

#pragma mark - 翻转字符串
void reverseString(char* s, int sSize) {
    // Tips:用异或交换更快速
    
    for (int i = 0; i<sSize/2; i++) {
        s[i] = s[i]^s[sSize-i-1];
        s[sSize-i-1] = s[i]^s[sSize-i-1];
        s[i] = s[i]^s[sSize-i-1];
    }
}

#pragma mark - 整数反转
// Tips:
//      1、 一次循环足以，每次循环的时候用之前的数据*10即可
//      2、溢出判断要在 'sum = (sum*10)+x%10;' 语句之前，否则如果新的sum溢出了是不能存储在int中的
int reverse(int x) {
    if (x>INT_MAX || x<-INT_MAX) {
        return 0;
    }
    
    int sum = 0;
    while (!(x<1) || !(x>-1)) {
        if (sum>INT_MAX/10 || sum<-INT_MAX/10) {
            return 0;
        }
        sum = (sum*10)+x%10;
        x = x/10;
    }
    
    printf("%d \n",sum);
    return sum;
}

#pragma mark - 字符串中的第一个唯一字符
// Tips:两次循环，一次通过hash来找到只出现一次的hash数组，第二次遍历，当前字符为hash数组中为出现一次时，即找到
int firstUniqChar(char * s) {
    
    // 第一次循环，初始化hash数组
    int i = 0;
    int number[26] = {0};
    while (s[i] != '\0') {
        int index = s[i]-'a';
        number[index]++;
        i++;
    }
    
    // 第二次循环，找到时return
    int j = 0;
    while (s[j] != '\0') {
        int index = s[j]-'a';
        if (number[index] == 1) {
            return j;
        }
        j++;
    }
    return -1;
}
