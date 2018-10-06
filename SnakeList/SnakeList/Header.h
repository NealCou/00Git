#pragma once
#pragma once
#include <iostream>

using namespace std;

typedef struct _Node
{
	int x, y;
	struct _Node *pre;
	struct _Node *next;
}Node, *pNode;

class DLlist
{
public:
	void InitDLlist();
	void InsertHead(int x, int y);
	void RemoveTail();
	void IncreseSize();

	Node *FindNode(int _x, int _y);

	Node *head;
	Node *tail;
	int size;
};

void DLlist::InitDLlist()
{
	head = new Node;
	head->x = 0;
	head->y = 0;
	head->next = head;
	head->pre = head;
	size = 0;
}

void DLlist::InsertHead(int x, int y)
{
	Node *node = new Node;
	node->x = x;
	node->y = y;
	node->next = head->next;
	head->next = node;

	node->pre = head;
	head->next->pre = node;
}

void DLlist::RemoveTail()
{
	Node *temp = head;
	int k = 0;
	while (k != size)
	{
		temp = temp->next;
		k++;
	}
	Node *t = temp->next;

	temp->next = t->next;
	t->next->pre = temp;
}

void DLlist::IncreseSize()
{
	size++;
}

Node *DLlist::FindNode(int _x, int _y)
{
	Node *temp = head->next;
	while (temp != head)
	{
		if (temp->x == _x && temp->y == _y)
		{
			return temp;
		}
		temp = temp->next;
	}
	return NULL;
}


