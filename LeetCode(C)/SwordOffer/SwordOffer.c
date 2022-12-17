//
//  SwordOffer.c
//  LeetCode(C)
//
//  Created by 贾辰 on 2022/11/17.
//  Copyright © 2022 贾辰. All rights reserved.
//

#include "SwordOffer.h"

/**
 * 003 数组中重复的数字
 */
int duplicate003(int* numbers, int numbersLen ) {
    // write code here
//    int *arr = malloc(sizeof(int)*(numbersLen));
    int arr[numbersLen];
    // todo 目前没想到更好的办法去初始化动态数组
    for (int j=0;j<numbersLen;j++) {
        arr[j] = -1;
    }

    for (int i=0;i<numbersLen;i++) {
        int value = numbers[i];
        if (arr[value] == -1) {
            arr[value] = value;
        } else {
            return value;
        }
    }
    return -1;
}

/**
* 004 二维数组中查找
    思路：仔细观察矩阵，可以发现：左下角元素为所在列最大元素，所在行最小元素
*/
bool find004(int target, int** array, int arrayRowLen, int* arrayColLen ) {
    // write code here
    int x = arrayRowLen-1;
    int y = 0;
    while (x>=0 && y<arrayColLen[x]) {
        int cur = array[x][y];
        if (cur > target) {
            x--;
        } else if (cur == target) {
            return true;
        } else {
            y++;
        }
    }
    return false;
}

/**
* 005 替换空格
    思路：仔细观察矩阵，可以发现：左下角元素为所在列最大元素，所在行最小元素
*/
char* replaceSpace005(char* s ) {
    // write code here
    // 这里暂时定全部为空格，因此新开辟的数组需要2n的长度，空间换时间。如果有需要可以添加一次循环，来精准确定具体的空格数量
    int length = strlen(s);
    char *output = (char *)malloc(sizeof(char)*length*3);
    
    int out_index = 0;
    for (int i = 0; s[i]!='\0'; i++) {
        if (s[i] == ' ') {
            output[out_index] = '%';
            output[out_index+1] = '2';
            output[out_index+2] = '0';
            out_index += 3;
        } else {
            output[out_index] = s[i];
            out_index++;
        }
    }
    return output;
}

/**
* 006 尾到头打印链表
    思路：1、遍历确定长度，逆序存入数组实现反转
*/

int* printListFromTailToHead006(struct ListNode* listNode, int* returnSize) {
    struct ListNode* p = listNode;
    int count = 0;
    // 确定链表长度
    while (p != NULL) {
        count++;
        p = p->next;
    }
    p = listNode;

    // 逆序放入数组
    int *stack = (int *)malloc(sizeof(int)*count);
    while (p != NULL) {
        count--;
        stack[count] = p->val;
        p = p->next;
    }
    return stack;
}

/**
* 007 构建二叉树
    思路：列数字找规律
        前： 1 2 4
        中： 2 1 4
    可以发现，根据前序的首位可以确定root，然后在中序中查找到对应的index，来决定左子和右子的长度
    当length为0时，退出递归
*/
struct TreeNode* reConstructBinaryTree(int* pre, int preLen, int* vin, int vinLen ) {
    // write code here
    struct TreeNode *root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = pre[0];
    
    if (preLen == 0 || vinLen ==0) {
        return NULL;
    }
    
    // 寻找root在中序中的位置
    int i=0;
    while (pre[0] != vin[i]) {
        i++;
    }
    
    root->left = reConstructBinaryTree(pre+1, i, vin, i);
    root->right = reConstructBinaryTree(pre+i+1, preLen-i-1, vin+i+1, vinLen-i-1);
    return root;
}

/**
* 008 二叉树的下一个节点
    中序： 左 根 右
    思路：分类讨论：
        1、pNode有右子树，找到右子树的最左节点返回即可
        2、pNode无右子树，判断父节点情况
            2.1 父节点是
 
    思路2:暴力法
        1、先通过pNode->next找到根节点
        2、中序遍历根节点，记录到一个数组中
        3、遍历数组，输出下一个值
*/
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
};
//struct TreeLinkNode* find_left(struct TreeLinkNode* pNode) {
//    if (pNode->left != NULL) {
//        return find_left(pNode->left);
//    } else if (pNode->right != NULL) {
//        // 这里有问题，当树是{2,#,3,#,4,#,5}时未通过
          // 需要改为最深的左子节点
//        return find_left(pNode->right);
//    }
//    return pNode;
//}
//
struct TreeLinkNode* GetNext(struct TreeLinkNode* pNode) {
    // 无右子，向上找父节点
    if (pNode->right == NULL) {
        struct TreeLinkNode* parentNode = pNode->next;
        if (parentNode == NULL) {
            return NULL;
        }
        // 如果发现当前树是某个根节点的左树，则跳出循环输出该根节点
        // 否则，证明当前树一直是根节点的右子树，且根节点已经输出过
        while (parentNode->left != pNode) {
            pNode = parentNode;
            parentNode = parentNode->next;
            if (parentNode == NULL) {
                return NULL;
            }
        }
        return parentNode;
    } else {
        pNode = pNode->right;
        // 有右子，输出右子中最深左子(没有则用当前1级右子)
        while (pNode->left != NULL) {
            pNode = pNode->left;
        }
        return pNode;
    }
}

/**
* 009 栈实现队列
    思路：push时往一个栈中push
        pop时，将栈1中数据放到栈2，实现反转然后再pop
*/
//class Solution
//{
//public:
//    void push(int node) {
//        stack1.push(node);
//    }
//
//    int pop() {
//        // 如果当前stack2中有数据，代表是之前先进栈的
//        // 因此需要先pop
//        if (stack2.size()>0) {
//            int res = stack2.top();
//            stack2.pop();
//            return res;
//        }
//
//        // 若stack2中没有数据，则从stack1中导入
//        while (stack1.size() > 0) {
//            int value = stack1.top();
//            stack1.pop();
//            stack2.push(value);
//        }
//        int res = stack2.top();
//        stack2.pop();
//        return res;
//    }
//
//    private:
//        stack<int> stack1;
//        stack<int> stack2;
//    };

/**
* 010 斐波那契数列
*/
int Fibonacci(int n ) {
    // write code here
    if(n==1 || n==2) {
        return 1;
    }
    return Fibonacci(n-1) + Fibonacci(n-2);
}

/**
 有一个长度为 n 的非降序数组，比如[1,2,3,4,5]，将它进行旋转，即把一个数组最开始的若干个元素搬到数组的末尾，变成一个旋转数组，比如变成了[3,4,5,1,2]，或者[4,5,1,2,3]这样的。请问，给定这样一个旋转数组，求数组中的最小值。

 要求：空间复杂度：O(1)O(1) ，时间复杂度：O(logn)O(logn)
 
* 011 寻找旋转数组中最小数字
    思路：多写用例整理发现：
            中位数>最有，则右侧具有拐点
            中位数<最右，则左侧具有拐点
    因此采用二分法，找到拐点即可
*/
int minNumberInRotateArray011(int* rotateArray, int rotateArrayLen) {
    // write code here
    if (rotateArrayLen == 0) {
        return 0;
    }
    int left = 0;
    int right = rotateArrayLen-1;
    
    while (left<right) {
        // mid需要每次根据left以及right去更新
        int mid = (left+right)/2;
        
        // 中位数大于最右，说明拐点在右边
        if (rotateArray[mid] > rotateArray[right]) {
            left = mid+1;
        } else if(rotateArray[mid] < rotateArray[right]) {
            // 拐点在左边;
            // ⚠️：这里不能是mid-1，因为会导致 {1,0,1,1,1};这样的输入，mid为0时，right=mid-1会导致right为第一项从而跳过最小值
            right = mid;
        } else {
            //⚠️：两值相等，因为题目说时非降序数组，因此可能会存在相同的情况，此时只要缩小范围即可
            right--;
        }
    }
    // 此时left = right
    return rotateArray[left];
}

/**
 给你一根长度为 n 的绳子，请把绳子剪成整数长的 m 段（ m 、 n 都是整数， n > 1 并且 m > 1 ， m <= n ），每段绳子的长度记为 k[1],...,k[m] 。请问 k[1]*k[2]*...*k[m] 可能的最大乘积是多少？例如，当绳子的长度是 8 时，我们把它剪成长度分别为 2、3、3 的三段，此时得到的最大乘积是 18

 要求：空间复杂度：O(1)O(1) ，时间复杂度：O(logn)O(logn)
 
* 014 剪绳子
    思路：m是自己定，因此可以决定是非还是不分，对于前一些数（2，3）不分是比分要大的
        一旦分出一段长度为1的小段，只会减少总长度，还不能增加乘积，因此长度为2的绳子不分比分开的乘积大，长度为3的绳子不分比分开的乘积大，长度为4的绳子分成2*2比较大
        多写用例整理发现：
            dp【1】 = 1
            dp【2】 = 2
            dp【3】 = 3
            dp【4】 = dp【2】*dp【2】=4
            dp【5】 = dp【2】*dp【3】=6
            中位数<最右，则左侧具有拐点
    因此采用二分法，找到拐点即可
*/
int max(int a,int b){
    if(a>b)
        return a;
    else return b;
}

int cutRope14(int number) {
    // write code here
    if (number<4) {
        return number-1;
    }
    
    int *dp = (int *)malloc(sizeof(int)*60);
    dp[1]=1;
    dp[2]=2;
    dp[3]=3;
    dp[4]=4;
    for (int i =5; i<=number; i++) {
        // 由于绳子最少切割1次，因此分为 j 和 i-j 两部分，以长度为5为例子
        // j=1 分为 1 和 4
        // j=2 分为 2 和 3
        dp[i] = 0;
        for (int j=1; j<i; j++) {
            // 这里第一个参数dp【i】表示当前记录的最大值结果，第二次参数表示此次计算得到的最大值
            dp[i] = max(dp[i],dp[j]*dp[i-j]);
        }
    }
    
    return dp[number];
}

