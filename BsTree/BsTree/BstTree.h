#pragma once


typedef struct _TreeNode
{
	int _data;
	struct _TreeNode *_left;
	struct _TreeNode *_right;
}TreeNode;

//////////////////////////////////////////////////////////////////////////
/// 搜索二叉树插入节点
void insertBstNodeIterator(TreeNode ** root,int data);

void insertBstNodeTraverse(TreeNode ** root, int data);

/// 二叉树的遍历
void preOrderTraverse(TreeNode * root);

void preOrderIterator(TreeNode * root);

void midOrderTraverse(TreeNode * root);

void midOrderIterator(TreeNode * root);

void postOrderTraverse(TreeNode * root);

void postOrderIterator(TreeNode * root);

/// 二叉树的层序遍历 用到了队列
void levelOrderTraverse(TreeNode * root);

/// 二叉树求树高
int getHeightByPostOrder(TreeNode * root);

/// 搜索二叉树查找
TreeNode * searchBstNodeIterator(TreeNode * root,int find);

TreeNode * searchBstNodeTraverse(TreeNode * root, int find);

/// 求搜索二叉树的最小值
TreeNode * getMinBstNode(TreeNode *root);

/// 求搜索二叉树的最大值
TreeNode * getMaxBstNode(TreeNode *root);

/// 求二叉搜索树的父节点
TreeNode * getBstParantNode(TreeNode * root, TreeNode * child);

/// 搜索二叉树结点删除
void deleteBstNode(TreeNode ** root, TreeNode * pfind);


