#include <stdio.h>
#include<stdlib.h>
#include "bstTree.h"

//typedef struct _TreeNode
//{
//	int _data;
//	struct _TreeNode * _left;
//	struct _TreeNode * _right;
//}TreeNode;

void insertBst(TreeNode **r, int data)
{
	TreeNode *t = (*r);
	if (t == NULL)
	{
		(*r) = (TreeNode *)malloc(sizeof(TreeNode));
		(*r)->_data = data;
		(*r)->_left = (*r)->_right = NULL;

	}
	else
		while (1)
		{
			if (data > t->_data)
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
}

void insertBstTraverse(TreeNode **r, int data)
{
	if ((*r) == NULL)
	{
		(*r) = (TreeNode *)malloc(sizeof(TreeNode));
		(*r)->_data = data;
		(*r)->_left = (*r)->_right = NULL;
	}
	else {
		if (data > (*r)->_data)
			insertBstTraverse(&(*r)->_right, data);
		else
			insertBstTraverse(&(*r)->_left, data);
	}
}



int main(int argc, char *argv[])
{
	TreeNode *root = NULL;
#if 0
	     10
        / \
      7     11
	/	\
	4	8
#endif;

	insertBstNodeTraverse(&root, 10);
	insertBstNodeTraverse(&root, 7);
	insertBstNodeTraverse(&root, 8);
	insertBstNodeTraverse(&root, 4);
	insertBstNodeTraverse(&root, 11);
	

	preOrderIterator(root);
	printf("\n");
	midOrderIterator(root);
	printf("\n");
	postOrderIterator(root);
	printf("\n");

	int height = getHeightByPostOrder(root);
	printf("%d ", height);

	TreeNode * min = getMinBstNode(root);
	printf("\n%d ", min->_data);

	TreeNode * max = getMaxBstNode(root);
	printf("\n%d ", max->_data);

	TreeNode * pfind = searchBstNodeTraverse(root,10);
	printf("\nfind resul:%d ", pfind->_data);

	TreeNode * parent = getBstParantNode(root, pfind);
	if (parent != NULL)
		printf("\nParents node :%d\n", parent->_data);
	else
		printf("\ncan't find parent!\n");

	deleteBstNode(&root, pfind);
	midOrderIterator(root);

	system("pause");
	return 0;
}
