//
//  Primary_String.h
//  LeetCode(C)
//
//  Created by 贾辰 on 2020/5/2.
//  Copyright © 2020 贾辰. All rights reserved.
//

#ifndef Primary_String_h
#define Primary_String_h

#include <stdio.h>

#pragma mark - 翻转字符串
void reverseString(char* s, int sSize);

#pragma mark - 整数反转
int reverse(int x);

#pragma mark - 字符串中的第一个唯一字符
int firstUniqChar(char * s);

#pragma mark - 有效的字母异位词（所有字符出现频率相同）
int isAnagram(char * s, char * t);

#pragma mark - 验证回文字符串
int isPalindrome(char * s);

#pragma mark - 字符串转换整数（atoi）
int myAtoi(char * str);

#pragma mark - 实现 strStr()
int strStr(char * haystack, char * needle);

#endif /* Primary_String_h */
