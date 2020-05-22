//
//  BinaryTree.h
//  LeetCode(C)
//
//  Created by 贾辰 on 2020/5/20.
//  Copyright © 2020 贾辰. All rights reserved.
//

#ifndef BinaryTree_h
#define BinaryTree_h

#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

#pragma mark - 初始化
// 通过数组 创建二叉树
struct TreeNode* createBinaryTree(long a[],int lenth, int index);

#pragma mark - 初级
/** 最大深度 */
int maxDepth(struct TreeNode* root);

/** 验证二叉搜索树 */
int isValidBST(struct TreeNode* root);

/** 对称二叉树 */
int isSymmetric(struct TreeNode* root); // 递归
int isSymmetricWithoutRecursion(struct TreeNode* root); // 非递归

/** 层序遍历二叉树 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes);
#endif /* BinaryTree_h */
