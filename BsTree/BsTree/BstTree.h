#pragma once


typedef struct _TreeNode
{
	int _data;
	struct _TreeNode *_left;
	struct _TreeNode *_right;
}TreeNode;

//////////////////////////////////////////////////////////////////////////
/// ��������������ڵ�
void insertBstNodeIterator(TreeNode ** root,int data);

void insertBstNodeTraverse(TreeNode ** root, int data);

/// �������ı���
void preOrderTraverse(TreeNode * root);

void preOrderIterator(TreeNode * root);

void midOrderTraverse(TreeNode * root);

void midOrderIterator(TreeNode * root);

void postOrderTraverse(TreeNode * root);

void postOrderIterator(TreeNode * root);

/// �������Ĳ������ �õ��˶���
void levelOrderTraverse(TreeNode * root);

/// ������������
int getHeightByPostOrder(TreeNode * root);

/// ��������������
TreeNode * searchBstNodeIterator(TreeNode * root,int find);

TreeNode * searchBstNodeTraverse(TreeNode * root, int find);

/// ����������������Сֵ
TreeNode * getMinBstNode(TreeNode *root);

/// �����������������ֵ
TreeNode * getMaxBstNode(TreeNode *root);

/// ������������ĸ��ڵ�
TreeNode * getBstParantNode(TreeNode * root, TreeNode * child);

/// �������������ɾ��
void deleteBstNode(TreeNode ** root, TreeNode * pfind);


