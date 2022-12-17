//
//  List.c
//  LeetCode(C)
//
//  Created by 贾辰 on 2020/5/11.
//  Copyright © 2020 贾辰. All rights reserved.
//

#include "List.h"
#include <stdlib.h>
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

// 通过数组 尾插法 初始化（头节不含数据）
/** 错误的创建方式（头节点包含数据）
 struct ListNode *head = (struct ListNode*)malloc(sizeof(struct ListNode));
 struct ListNode *cur = head;
 for (int i = 1; i<4; i++) {
     cur->val = i;
     struct ListNode *next = (struct ListNode*)malloc(sizeof(struct ListNode));
     next->val = -1;
     cur->next = next;
     cur = next;
 }
 cur = NULL;
 // 将cur置空，但是当前节点已经创建出内存，因此对于head指针，里面依旧有4个元素，所以错误
*/
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
// ⚠️ node->next = node->next->next; 这样是删除node的下一节点
// ⚠️ 加上 node->val = node->next->val; 这样是删除的当前节点（相当于把下一节点的值替换到当前节点，丢弃了当前节点的值）
void deleteNode(struct ListNode* node) {
    node->val = node->next->val;
    node->next = node->next->next;
}

#pragma mark - 【初级】 删除链表的倒数第N个节点
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *fast = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *slow = (struct ListNode*)malloc(sizeof(struct ListNode));
    
    fast->next = head;
    slow->next = head;
    // 这样定义一个头指针，作用是保证数组中只有一个时，下面快指针先跑的循环不会溢出
    
    // 快指针先跑n+1(跑n+1代表快慢指针间差n+1，这个slow->next才为要删除的节点)
    for (int i = 0; i< n+1; i++) {
        fast = fast->next;
    }
    
    // 一起跑
    while (fast != NULL) {
        slow = slow->next;
        fast = fast->next;
    }

    if (slow->next == head) {
        // 删除头节点
        return head->next;
    } else if (slow->next == NULL) {
        // 删除末尾节点
        slow->next = NULL;
        return head;
    } else {
        // 替换slow的下一节点（⚠️不要加上 slow->val = slow->next->val 加上后变成删除当前节点了）
//        slow->val = slow->next->val;
        slow->next = slow->next->next;
        return head;
    }

    return head;
}

#pragma mark - 反转链表
// 本质上是三个指针
// 优化：当前指针可以使用head，这样创建两个即可
struct ListNode* reverseList(struct ListNode* head) {

    if (head == NULL) {
        return head;
    }
    
    struct ListNode *pre = NULL;
    struct ListNode *after = head->next;

    while (after != NULL) {
        head->next = pre;
        
        pre = head;
        head = after;
        after = after->next;
    }
    head->next = pre;
    
    return head;
}
// https://blog.csdn.net/xiashanrenlaozhang/article/details/80834701
// 递归解法
struct ListNode* reverseList_recursion(struct ListNode* head) {

    if (head->next == NULL) {
        return head;
    }
    struct ListNode *p = reverseList_recursion(head->next);
    p->next = head;
    return p;
}

#pragma mark - 合并两个有序链表（思考递归解法）
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *head = (struct ListNode*)malloc(sizeof(struct ListNode));
    // 这里注意将headNext赋NULL，（相当于初始化），否则l1和l2传入空串时，返回 head->next 会有问题
    head->next = NULL;
    struct ListNode *l = head;
    
    while (l1 !=NULL && l2 != NULL) {
        if (l1->val <= l2->val) {
            l->next = l1;
            l1 = l1->next;
            
        } else {
            l->next = l2;
            l2 = l2->next;
        }
        
        l = l->next;
    }
    
    // 此时不需要去循环，因为l1和l2必定有一个里面还有值，将l的next指向有值的剩余串即可
    if (l1 == NULL) {
        l->next = l2;
    } else {
        l->next = l1;
    }
    
    return head->next;
}

#pragma mark - 回文链表
// 反转链表+寻找链表中间节点
int isPalindromeList(struct ListNode* head) {
    struct ListNode *h = (struct ListNode*)malloc(sizeof(struct ListNode));
    h->next = head;
    
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    
    // 通过循环确定中间节点slow
    int length =0;
    while (fast != NULL) {
        length++;
        fast = fast->next;
        
        if (length%2 == 0) {
            slow = slow->next;
        }
    }
    
    if (length<=1) {
        return 1;
    }
    
    // 将slow之后的节点进行翻转
    struct ListNode *pre = NULL;
    struct ListNode *mid = slow;
    struct ListNode *after = slow->next;
    while (after!=NULL) {
        mid->next = pre;
        pre = mid;
        mid = after;
        after = after->next;
    }
    mid->next = pre;

    struct ListNode *rList = mid;   // 翻转后的链表
    logList(rList);

    // 用head和反转后的链表开始比较
    while (rList!= NULL) {
        if (head->val != rList->val) {
            return 0;
        } else {
            head = head->next;
            rList = rList->next;
        }
    }
    
    return 1;
}

#pragma mark - 环形链表
// 方法1:快慢指针
// 方法2:以指针地址为key做hash表，如果冲突则表明存在重复
int hasCycle(struct ListNode *head) {
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    int length = 0;
    
    while (fast != NULL) {
        length++;
        fast = fast->next;
        
        if (length%2 == 0) {
            slow = slow->next;
        }
        
        if (fast == slow) {
            return 1;
        }
    }
    return 0;
}
