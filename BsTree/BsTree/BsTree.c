#include "bstTree.h"
#include "mystack.h"
#include <stdio.h>
#include <malloc.h>


/// 搜索二叉树插入节点
void insertBstNodeIterator(TreeNode **root, int data)
{
	TreeNode *t = *root;
	if (*root == NULL)
	{
		(*root) = (TreeNode *)malloc(sizeof(TreeNode));
		(*root)->_data = data;
		(*root)->_left = (*root)->_right = NULL;
	}
	else
	{
		while (t->_data != data)		// t->_data != data
		{
			if (t->_data<data)
			{
				if (t->_right == NULL)
				{
					t->_right = (TreeNode *)malloc(sizeof(TreeNode));
					t->_right->_data = data;
					t->_right->_left = t->_right->_right = NULL;
					break;
				}
				t = t->_right;
			}
			else
			{
				if (t->_left == NULL)
				{
					t->_left = (TreeNode *)malloc(sizeof(TreeNode));
					t->_left->_data = data;
					t->_left->_left = t->_left->_right = NULL;
					break;
				}
				t = t->_left;
			}
		}
		return ;
	}
}

void insertBstNodeTraverse(TreeNode ** root, int data)
{
	if (*root == NULL)
	{
		*root = (TreeNode *)malloc(sizeof(TreeNode));
		(*root)->_data = data;
		(*root)->_left = (*root)->_right = NULL;
	}
	else
	{
		if ((*root)->_data > data)
			insertBstNodeTraverse(&((*root)->_left), data);
		else if ((*root)->_data < data)
			insertBstNodeTraverse(&((*root)->_right), data);
		else
			return;		
	}
}

/// 二叉树的遍历
void preOrderTraverse(TreeNode * root)
{
	if (root != NULL)
	{
		printf("%d ", root->_data);
		preOrderTraverse(root->_left);
		preOrderTraverse(root->_right);
	}
}

void preOrderIterator(TreeNode * root)
{
	if (root != NULL)
	{
		Stack s;
		initStack(&s);

		while (root || !isStackEmpty(&s))
		{
			while (root)
			{
				printf("%d ", root->_data);
				Push(&s, root);
				root = root->_left;
			}
			root = Pop(&s);
			root = root->_right;
		}		
	}
}

void midOrderTraverse(TreeNode * root)
{
	if (root != NULL)
	{
		midOrderTraverse(root->_left);
		printf("%d ", root->_data);
		midOrderTraverse(root->_right);
	}
}

void midOrderIterator(TreeNode * root)
{
	if (root != NULL)
	{
		Stack s;
		initStack(&s);

		while (root || !isStackEmpty(&s))
		{
			while (root)
			{
				Push(&s, root);
				root = root->_left;
			}
			root = Pop(&s);
			printf("%d ", root->_data);
			root = root->_right;
		}
	}
}

void postOrderTraverse(TreeNode * root)
{
	if (root != NULL)
	{
		postOrderTraverse(root->_left);
		postOrderTraverse(root->_right);
		printf("%d ", root->_data);
	}
}

void postOrderIterator(TreeNode * root)
{
	if (root)
	{
		Stack s;
		initStack(&s);
		TreeNode * cur = NULL;
		TreeNode * pre = NULL;
		Push(&s,root);
		while (!isStackEmpty(&s))
		{
			cur = Pop(&s);
			Push(&s, cur);
			if ((cur->_left == NULL && cur->_right == NULL) ||
				/*(pre != NULL&&(pre == cur->_left||pre == cur->_left))*/
				(pre != NULL && (pre == cur->_left || pre == cur->_right)))
			{
				printf("%d ", cur->_data);
				Pop(&s);
				pre = cur;
			}
			else
			{
				if (cur->_right != NULL)
					Push(&s, cur->_right);
				if (cur->_left != NULL)
					Push(&s, cur->_left);				
			}
		}
	}
}


void levelOrderTraverse(TreeNode * root);

/// 二叉树求树高
int getHeightByPostOrder(TreeNode * root)
{
	int lH, rH, MaxH;
	if (root)
	{
		lH = getHeightByPostOrder(root->_left);
		rH = getHeightByPostOrder(root->_right);
		MaxH = (lH > rH) ? lH : rH;
		return MaxH + 1;
	}
	return 0;
}

/// 搜索二叉树查找
TreeNode * searchBstNodeIterator(TreeNode * root, int find)
{
	while (root)
	{
		if (root->_data == find)
			return root;
		else if (root->_data > find)
			root = root->_left;
		else
			root = root->_right;
	}
	return NULL;
}

TreeNode * searchBstNodeTraverse(TreeNode * root, int find)
{
	if (root)
	{
		if (root->_data == find)
			return root;
		else if (root->_data > find)
			return searchBstNodeTraverse(root->_left, find);
		else
			return searchBstNodeTraverse(root->_right, find);
	}
	return NULL;
}

/// 求搜索二叉树的最小值
TreeNode * getMinBstNode(TreeNode *root)
{
	if (root)
	{
		while (root->_left)
			root = root->_left;
		return root;
	}
	return NULL;

}

/// 求搜索二叉树的最大值
TreeNode * getMaxBstNode(TreeNode *root)
{
	if (root)
	{
		while (root->_right)
			root = root->_right;
		return root;
	}
	return NULL;
}

/// 求二叉搜索树的父节点
TreeNode * getBstParantNode(TreeNode * root,TreeNode * child)
{
	static TreeNode * Parent = NULL;
	if (root)
	{
		if (root->_left == child || root->_right == child)
			Parent = root;
		getBstParantNode(root->_left, child);
		getBstParantNode(root->_right, child);
	}
	return Parent;

}


void deleteBstNode(TreeNode ** root, TreeNode * pfind)
{
	TreeNode *t = (*root);
	TreeNode *minRight;

	if (t == NULL || pfind == NULL)
		return;

	TreeNode *Parent = getBstParantNode(t, pfind);

	if (pfind->_left == NULL&&pfind->_right == NULL)
	{
		if (t == pfind)
		{
			free(*root);
			(*root) = NULL;
		}

		if (Parent)
		{
			if (Parent->_left == pfind)
			{
				free(Parent->_left);
				Parent->_left = NULL;
			}
			else
			{
				free(Parent->_right);
				Parent->_right = NULL;
			}
		}
	}
	else if (pfind->_left == NULL&&pfind->_right != NULL)
	{
		if (pfind == (*root))
		{
			(*root) = t->_right;
			free(t);
			return;
		}
		if (Parent)
		{
			if (Parent->_left == pfind)
			{
				Parent->_left = pfind->_right;
				free(pfind);
			}
			else
			{
				Parent->_right = pfind->_right;
				free(pfind);
			}
		}
	}
	else if (pfind->_left != NULL&&pfind->_right == NULL)
	{
		if (pfind == (*root))
		{
			(*root) = t->_left;
			free(t);
			return;
		}
		if (Parent->_left == pfind)
		{
			Parent->_left = pfind->_left;
			free(pfind);
		}
		else
		{
			Parent->_right = pfind->_left;
			free(pfind);
		}
	}
	else
	{
		minRight = getMinBstNode(pfind->_right);
		pfind->_data = minRight->_data;

		Parent = getBstParantNode(*root, minRight);
		if (Parent != pfind)
			Parent->_left = minRight->_right;
		else
			Parent->_right = minRight->_right;
		free(minRight);
	}

}
