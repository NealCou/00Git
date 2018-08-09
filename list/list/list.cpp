#include"list.h"
#include<stdio.h>


Node * creatList()
{
	Node * head = (Node*)malloc(sizeof(Node));
	head->next = NULL;
	return head;
}

Node * searchList(Node * head, int find)
{
	head = head->next;
	while (head)
	{
		if (head->data == find)
			break;
		head = head->next;
	}
	return head;
}

void insertList(Node * head, int data)
{
	Node * cur = (Node *)malloc(sizeof(Node));
	cur->next = head->next;
	cur->data = data;
	head->next = cur;
}

void traverseList(Node * head1)
{
	head1 = head1->next;
	while (head1)
	{
		printf("%2d  ", head1->data);
		head1 = head1->next;
	}
}

int lenList(Node * head)
{
	int count = 0;
	head = head->next;
	while (head)
	{
		count++;
		head = head->next;
	}
	return count;
}

void deleteList(Node * head, Node *pfind)
{
	if (pfind->next == NULL) {
		while (head->next != pfind)
			head = head->next;
		head->next = pfind->next;
		free(pfind);
	}
	else {
		Node * t = pfind->next;
		pfind->data = t->data;
		pfind->next = t->next;
		free(t);
	}
}

void popSortList(Node * head)
{

	// exchange data;
	Node * p, *q;
	int len = lenList(head);
	for (int i = 0; i < len - 1; i++)
	{
		p = head->next;
		q = p->next;
		for (int j = 0; j < len - i - 1; j++)
		{
			if (p->data > q->data)
			{
				p->data ^= q->data;
				q->data ^= p->data;
				p->data ^= q->data;
			}
			p = p->next;
			q = p->next;
		}
	}


}

void reverseList(Node * head)
{

}

void destroyList(Node * head)
{

}
