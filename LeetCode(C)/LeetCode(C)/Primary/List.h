//
//  List.h
//  LeetCode(C)
//
//  Created by 贾辰 on 2020/5/11.
//  Copyright © 2020 贾辰. All rights reserved.
//

#ifndef List_h
#define List_h

#include <stdio.h>

struct ListNode {
     int val;
     struct ListNode *next;
};

#pragma mark - 初始化
// 通过数组 头插法 初始化（头节点含数据）
struct ListNode* createListWithHeadInsert(int a[],int lenth);

// 通过数组 尾插法 初始化（头节点含数据）
struct ListNode* createListWithTailInsert(int a[],int lenth);

/** 返回第n个节点*/
//struct ListNode* getNode(struct ListNode *head,int n);

void logList(struct ListNode* head);

#pragma mark - 初级
/** 删除目标节点 */
void deleteNode(struct ListNode* node);

/** 删除链表的倒数第N个节点 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n);

/** 反转链表 */
struct ListNode* reverseList(struct ListNode* head);

#endif /* List_h */
