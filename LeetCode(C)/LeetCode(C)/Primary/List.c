//
//  List.c
//  LeetCode(C)
//
//  Created by 贾辰 on 2020/5/11.
//  Copyright © 2020 贾辰. All rights reserved.
//

#include "List.h"

#pragma mark - 【初始化】

// 通过数组 头插法 初始化（头节点含数据）
struct ListNode* createListWithHeadInsert(int a[],int lenth) {
//    struct ListNode *current = (struct ListNode*)malloc(sizeof(struct ListNode));
//    current->next = NULL;
    // 初始化的时候，头节点要为空，否则结尾会多一个节点
    struct ListNode *head = NULL;
    
    for (int i =0; i<lenth; i++) {
        struct ListNode *p = (struct ListNode*)malloc(sizeof(struct ListNode));
        p->val = a[i];
        p->next = head;
        
        head = p;
    }
    
    return head;
}

// 通过数组 尾插法 初始化（头节点含数据）
struct ListNode* createListWithTailInsert(int a[],int lenth) {
    struct ListNode *head = (struct ListNode*)malloc(sizeof(struct ListNode));
    
    struct ListNode *current = head; // current 指向尾节点
    for (int i =0; i<lenth; i++) {
        struct ListNode *p = (struct ListNode*)malloc(sizeof(struct ListNode));
        p->val = a[i];
        
        current->next = p;
        
        current = p;
    }
    current->next = NULL;
    
    // 由于head节点不存值，因此返回head->next
    return head->next;
}


///** 返回第n个节点*/
//struct ListNode* getNode(struct ListNode *head,int n) {
//
//}

void logList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d ->",head->val);
        head = head->next;
    }
    printf("NULL \n");
}

#pragma mark - 【初级】 删除节点
// ⚠️这里题目要求是删除非末尾节点，所以可以。如果删除末尾节点会有问题
void deleteNode(struct ListNode* node) {
    node->val = node->next->val;
    node->next = node->next->next;
}

#pragma mark - 【初级】 删除链表的倒数第N个节点
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    
    // 快指针先跑n+1(跑n+1代表快慢指针间差n+1，这个slow->next才为要删除的节点)
    for (int i = 0; i< n; i++) {
        fast = fast->next;
    }
    
    // 一起跑
    while (fast != NULL) {
        slow = slow->next;
        fast = fast->next;
    }
    
    if (slow == head) {
        // 删除头节点
        return head->next;
    } else if (slow->next == NULL) {
        // 删除末尾节点
        slow->next = NULL;
        return head;
    } else {
        slow->val = slow->next->val;
        slow->next = slow->next->next;
        return head;
    }
}
