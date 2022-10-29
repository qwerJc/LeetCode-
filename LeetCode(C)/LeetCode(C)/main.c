//
//  main.c
//  LeetCode(C)
//
//  Created by 贾辰 on 2018/12/21.
//  Copyright © 2018年 贾辰. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Primary/Primary_Array.h"

//#include "Primary_String.h"
#include "List.h"
#include "BinaryTree.h"

void testValidSudoku(void) {
    char board[10][10] = {{'9','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    
    char  **s ;
    s = (char **) malloc(sizeof(char**));
    for (int i = 0; i<9; i++) {
        *(s+i) =  board[i];
    }
    
    for (int i1 = 0; i1<9; i1++) {
        for (int j1 = 0; j1<9; j1++) {
            printf(" %c ",s[i1][j1]);
        }
        printf("\n\n");
    }
    
    int colSize[] = {9,9,9,9,9,9,9,9,9};
    
    isValidSudoku(s, 9, colSize);
}

// 函数声明
void testPrimaryArray(void) {
//    int arr1[3] = {4,9,5};
//    int arr2[5] = {9,4,9,8,4};
//    int arr3[5] = {9,4,9,9,9};
//    int arr4[6] = {9,9,9,9,9,9};
//    int *returnArr;

/** 删除排序数组中重复项 */
//    int arr_input[15] = {1,1,2};
    int arr_input[15] = {0,0,1,1,1,2,2,3,3,4};
    int new_size = removeDuplicates(arr_input, 10);
    printIntArrWithoutLineBreak(arr_input, new_size);
    
/** 加1 */
//    int arrLength;
//    returnArr = plusOne(arr4, 6, &arrLength);
//    printIntArrWithoutLineBreak(returnArr, arrLength);
    
/** 移动0 */
//    int arrZero1[5] = {7,1,0,3,12};
//    int arrZero2[1] = {0};
//    int arrZero[15] = {0,5,0,1,0,0,0,0,3,7,0,0,12,0,0};
//    moveZeroes(arrZero1, 5);
//    printIntArrWithoutLineBreak(arrZero1, 5);

    // 有效的数独
//    testValidSudoku();
    
    // 旋转图像
//    int input[3][3] = {1,2,3,4,5,6,7,8,9};
//    int lenght[3] = {3,3,3};
//    int **in = (int**)malloc(sizeof(int**));
//    for (int i = 0; i<3; i++) {
//        in[i] = input[i];
//    }
//    rotate(in, 3, lenght);
}

void testString(void) {
    /** 反转字符串 */
//    char s[6] = {'H','a','n','n','a','h'};
//    reverseString(s, 6);
    
    /** 整数反转 */
//    reverse(123);
//    reverse(-123);
//    reverse(120);
//    reverse(1534236469);
    
    /** 字符串中唯一字符 */
//    char *s = "leetcode";
//    firstUniqChar(s);
    
    /** 有效的字母异位词 */
//    isAnagram("anagram", "nagaram");
//    isAnagram("ab", "a");
    
    /** 验证回文字符串 */
//    isPalindrome("race a car");
//    isPalindrome("A man, a plan, a canal: Panama");
    
    /** 字符串转换整数 (atoi)*/
    printf("%d \n", myAtoi("+-2"));
    printf("%d \n", myAtoi("   -42"));
    printf("%d \n", myAtoi("4193 with words"));
    printf("%d \n", myAtoi("words and 987"));
    printf("%d \n", myAtoi("-91283472332"));
    printf("%d \n", myAtoi("-000000000000000000000000000000000000000000000000001"));
    printf("%d \n", myAtoi("   +0 123"));
    printf("%d \n", myAtoi("-2147483648"));
    printf("%d \n", myAtoi("-A1"));
}

void testList(void) {
    int arr1[5] = {1,2,3,4,5};
    struct ListNode *list1 = createListWithTailInsert(arr1, 5);
    
    int arr2[2] = {1,2};
    struct ListNode *list2 = createListWithTailInsert(arr2, 2);
    
    int arr3[1] = {1};
    struct ListNode *list3 = createListWithHeadInsert(arr3, 1);
    
    int arr4[0] = {};
    struct ListNode *list4 = createListWithHeadInsert(arr4, 0);
    
    int arr5[8] = {1,3,2,4,4,2,3,1};
    struct ListNode *list5 = createListWithHeadInsert(arr5, 8);
    
    int arr6[9] = {1,3,2,4,5,4,8,3,1};
    struct ListNode *list6 = createListWithHeadInsert(arr6, 9);
    
    
    // 删除节点
//struct ListNode *list1 = createListWithTailInsert(arr1, 5);
//logList(list1);
//    struct ListNode *p = list1;
//    while (p->next != NULL) {
//        p = p->next;
//    }
//    deleteNode(p);
//    logList(list1);
    
    // 删除倒数第n个节点
//    struct ListNode *newList1 = removeNthFromEnd(list1, 2);
//    logList(newList1);
//    
//    struct ListNode *list2 = createListWithHeadInsert(arr2, 2);
//    logList(list2);
//    struct ListNode *newList2 = removeNthFromEnd(list2, 1);
//    logList(newList2);
//    
//    struct ListNode *list3 = createListWithHeadInsert(arr3, 1);
//    logList(list3);
//    struct ListNode *newList3 = removeNthFromEnd(list3, 1);
//    logList(newList3);
    
//    logList(list1);
//    struct ListNode *newList1 = reverseList(list1);
//    logList(newList1);
    
//    // 反转链表
//    logList(list4);
//    struct ListNode *newList4 = reverseList(list4);
//    logList(newList4);
    
//    // 合并链表
//    logList(list1);
//    logList(list2);
//    struct ListNode *newList5 = mergeTwoLists(list1, list2);
//    logList(newList5);
    
    logList(list5);
    isPalindromeList(list5);
    
    logList(list6);
    isPalindromeList(list6);
    
    logList(list2);
    isPalindromeList(list2);
    
    logList(list4);
    isPalindromeList(list4);
}

void testBinaryTree(void) {
    
    int arr1[7] = {3,9,20,NULL,NULL,15,7};
    struct TreeNode* root1 = createBinaryTree(arr1, 7, 0);
    
    int arr2[3] = {2,1,3};
    struct TreeNode* root2 = createBinaryTree(arr2, 3, 0);

    int arr3[7] = {10,5,15,NULL,NULL,6,20};
    struct TreeNode *root3 = createBinaryTree(arr3, 7, 0);
    
    long arr4[1] = {2147483647};
    struct TreeNode *root4 = createBinaryTree(arr4, 1, 0);
    
    long arr5[2] = {2147483647,2147483647};
    struct TreeNode *root5 = createBinaryTree(arr5, 2, 0);
    
    long arr6[7] = {1,2,2,3,4,4,3};
    struct TreeNode *root6 = createBinaryTree(arr6, 7, 0);
    
    // 最大深度
//    printf("Depth : %d",maxDepth(root1));
    
    // 验证二叉搜索树
//    int res = isValidBST(root2);
//    int res = isValidBST(root3);
//    int res = isValidBST(root5);
    
    
    // 对称二叉树
//    int res = isSymmetric(root6);
//    int res = isSymmetricWithoutRecursion(root6);
    
    // 层序遍历二叉树

}
#pragma mark - main
int main(int argc, const char * argv[]) {
//    testPrimaryArray();
    
//    testString();
    
//    testList();
    
//    int a[INT_MAX];
//    a[0] = 1;
//    printf("%d",a[0]);
    
//    int queue[INT_MAX];
//    queue[0] = 1;
//    queue[1] = 2;
//    printf("%d",queue[0]);
    
    
    
//    testBinaryTree();

    return 0;
}

// 分割数组
//https://leetcode.cn/problems/partition-array-into-disjoint-intervals/
int partitionDisjoint(int* nums, int numsSize){
    int left_index = 0;
    int right_index = numsSize-1;

    int left_max_value = nums[left_index];
    int right_min_value = nums[right_index];

    for (int i = 0; i < numsSize ; i++) {
        int left_value = nums[left_index];
        int right_value = nums[right_index];

        if (left_max_value <= right_min_value) {
            right_index--;
            right_min_value = right_value<right_min_value ? right_value : right_min_value;
        } else {
            left_index++;
            left_max_value = left_value>left_max_value ? left_value : left_max_value;
        }
    }
    return left_index+1;
}
