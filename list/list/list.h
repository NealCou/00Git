#pragma once
#ifndef LIST_H
#define LIST_H
typedef struct _Node
{
	int data;
	struct _Node * next;
}Node;

Node * creatList();         //
Node * searchList(Node * head, int find);

void insertList(Node * head, int data);
void traverseList(Node * head1);
int lenList(Node * head);

void deleteList(Node * head, Node *pfind);
void popSortList(Node * head);
void reverseList(Node * head);
void destroyList(Node * head);



#endif // LIST_H
