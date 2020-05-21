//
//  BinaryTree.c
//  LeetCode(C)
//
//  Created by 贾辰 on 2020/5/20.
//  Copyright © 2020 贾辰. All rights reserved.
//

#include "BinaryTree.h"
#include <limits.h>

#pragma mark - 【初始化】
// 创建二叉树
// {3,9,20,NULL,NULL,15,7};
struct TreeNode* createBinaryTree(long a[],int lenth, int index) {
    if (index >= lenth) {
        return NULL;
    }
    struct TreeNode *node = NULL;
    if (a[index] != NULL) {
        node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        node->val = a[index];
        node->left = createBinaryTree(a, lenth, index*2+1);
        node->right = createBinaryTree(a, lenth, index*2+2);
    }
    return node;
}

// 前序
void PreOrder(struct TreeNode *root) {
    if (root == NULL) {
        return;
    }
    printf("%d \n",root->val);
    PreOrder(root->left);
    PreOrder(root->right);
}

#pragma mark - 初级 - 最大深度
int maxDepth(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    if (leftDepth>=rightDepth) {
        return leftDepth+1;
    } else {
        return rightDepth+1;
    }
}

#pragma mark - 初级 - 验证二叉搜索树 - 方法1:传入上下边界
// 思路：
//      1、首先需要保证节点的左子树小于它，右子树都大于它
//      2、但只这样容易出问题，因为对于某个节点而言，除了满足和父节点的规律，还需满足整个子树的规律
//            即：左子树的整体需要都小于其根节点，即左子树的右子节点需要大于左子树的根节点，同时，右子节点小于左子树的根节点
//      3、因此需要明确上下边界
//      4、注意溢出判断（直接传 LONG_MIN）

int isValidBST(struct TreeNode* root){
    // 方法一
//    return checkBST(root, LONG_MIN, LONG_MAX);
    
    // 方法2
    long value = LONG_MIN;
    return inOrderTraverseBST(root,&value);
}

// 方法一：传入上下边界，检查左子树的节点的最大节点小于upper，检查右子树的最小节点大于lower
// 时间复杂度 O(n)
// 空间复杂度 大于O(1),最坏O(n) (递归函数在递归过程中需要为每一层递归函数分配栈空间，所以这里需要额外的空间且该空间取决于递归的深度，即二叉树的高度)
int checkBST(struct TreeNode* root, long lower, long upper) {
    if (root == NULL) {
        return 1;
    }
    
    if (lower<root->val && root->val<upper) {
        int leftRes = checkBST(root->left, lower, root->val);
        int rightRes = checkBST(root->right, root->val, upper);
        
        return leftRes && rightRes;
    }
    return 0;
}
#pragma mark - 初级 - 验证二叉搜索树 - 方法2 中序遍历
// 方法二： 中序遍历二叉搜索树,传入上一节点的值，判断当前节点是否大于上一节点
//    对于左子节点，一直进入递归，直到最左子为NULL，此时当前的节点为有值的最子节点，此时判断完了更新前一节点的值
//    对于根节点，执行完了对左节点的判断后，此时preNodeValue已经被更新了，可以直接判断，判断完了更新前一节点的值
//    对于右节点，执行完了根节点的判断，此时preNodeValue被更新，直接比较

// 空间复杂度和时间负责度 和法一相同

int inOrderTraverseBST(struct TreeNode* root,long *preNodeValue) {
    if (root == NULL) {
        return 1;
    }
    // 左
    int lRes = inOrderTraverseBST(root->left,preNodeValue);

    // 根
    int rootRes = 0;
    if (root->val> *preNodeValue) {
        rootRes = 1;
    }
    
    *preNodeValue = root->val;

    int rRes = inOrderTraverseBST(root->right,preNodeValue);
    
    return lRes&&rootRes&&rRes;
}

#pragma mark - 初级 - 对称二叉树
int isSymmetric(struct TreeNode* root) {
    if (root == NULL) {
        return 1;
    }
    return checkSymetric(root->left, root->right);
}

int checkSymetric(struct TreeNode* tree1,struct TreeNode *tree2) {
    if (tree1 == NULL && tree2 == NULL) {
        return 1;
    }
    
    if (tree1 == NULL || tree2 == NULL) {
        return 0;
    }
    
    if (tree1->val == tree2->val) {
        int lRes = checkSymetric(tree1->left, tree2->right);
        int rRes = checkSymetric(tree1->right, tree2->left);
        return lRes&&rRes;
    }
    
    return 0;
}
