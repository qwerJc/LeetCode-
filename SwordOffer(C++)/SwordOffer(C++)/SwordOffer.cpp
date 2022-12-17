//
//  SwordOffer.cpp
//  SwordOffer(C++)
//
//  Created by 贾辰 on 2022/11/19.
//  Copyright © 2022 贾辰. All rights reserved.
//

#include "SwordOffer.hpp"
#include <vector>
#include <queue>

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
    val(x), next(NULL) {
    }
};

/**
* 006 尾到头打印链表
思路：栈,递归，头插法更改链表
*/
class Solution {
public:
    std::vector<int> printListFromTailToHead(ListNode* head) {
        ListNode *cur = head;
//        std::stack
        std::queue<int> que;
        que.po
        while (cur != nullptr) {
            
        }
    }
};
