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
// ⚠️：如果给出数组的长度，逆序遍历，然后用一个指针记者当前第二次出现的位置，一边添加hash数组一边遍历即可
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

#pragma mark - 有效的字母异位词（出现频率相同）
// Tips：也可以先排序再比较
int isAnagram(char * s, char * t) {
    int hash[26] = {0};
    
    // 第一次循环，遍历字符串a并确定hash
    for (int i=0; s[i]!='\0'; i++) {
        int index = s[i]-'a';
        
        if (index<0 || index>25) {
            continue;
        } else {
            hash[index]++;
        }
    }
    
    // 第二次循环，遍历字符串b，如果有hash中没有的则返回0
    for (int j=0; t[j]!='\0'; j++) {
        int index = t[j]-'a';
        
        if (index<0 || index>25) {
            continue;
        } else {
            if (hash[index]==0) {
                return 0;
            } else {
                hash[index]--;
            }
        }
    }
    
    // 看hash中是否还有不为0的字符，即字符串s中存在但字符串t中不存在
    for (int z = 0; z<26; z++) {
        if (hash[z]>0) {
            return 0;
        }
    }
    
    return 1;
}

#pragma mark - 验证回文字符串
// Tips:用两个指针，分别从左右两端往中间扫，如果当前的值不合法，则移动指针
// 用于返回字符c对应的ASCII值
int getASCIIValue(char c) {
    if (('0'<=c && c<='9') || ('A'<=c && c<='Z')) {
        return c;
    } else if ('a'<=c && c<='z') {
        return c - 'a' + 'A';
    } else {
        return -1;
    }
}
int isPalindrome(char * s) {
    int length = 0;
    while (s[length] != '\0') {
        length++;
    }
    
    if (length == 0) {
        return 1;
    }
    
    int left = 0;
    int right = length-1;
    while ((right-left) >= 1) {
        int leftValue = getASCIIValue(s[left]);
        if (leftValue < 0) {
            left++;
            continue;
        }
        
        int rightValue = getASCIIValue(s[right]);
        if (rightValue < 0) {
            right--;
            continue;
        }

        if (leftValue == rightValue) {
            left++;
            right--;
        } else {
            return 0;
        }
    }
    return 1;
}

#pragma mark - 字符串转换整数（atoi）
// Tips：
//      1、⚠️这里符号判断只能判断一次，"+-2"这种输入应该返回结果0
//      2、溢出判断可以用long
int myAtoi(char * str) {

    int flag = 1;
    long res=0;
    int isStart = 0;
    
    int index=0;
    
    // 当前输入位为0，指针后移
    while(str[index] != '\0' && str[index] == ' '){
        ++index;
    }
    
    // 当前为符号
    if (str[index] == '-') {
        flag = -1;
        index++;
    } else if (str[index] == '+') {
        flag = 1;
        index++;
    }
    
     // 计算当前数字
    while ('0'<=str[index] && str[index]<='9') {
        isStart = 1;
        int number = str[index] - '0';
        res = res*10 + number;
        
        // 溢出判断
        if ((int)res != res) {
            return (flag==1) ? INT_MAX : INT_MIN;
        }
        
        index++;
    }
    
    return (int)res*flag;
}


#pragma mark - 实现 strStr()
int strStr(char * haystack, char * needle) {
//    int n_l = strlen(needle);
//    
//    if (needle[0] == '\0') {
//        return 0;
//    }
//    
//    for (int i = 0; needle[i]!='\0'; i++) {
//        for (int j = 0; haystack[j]!='\0'; j++) {
//            if (needle[i]) {
//                <#statements#>
//            }
//        }
//    }
    
    return -1;
}
