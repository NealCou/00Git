#pragma once
#ifndef MYSTACK_H
#define MYSTACK_H

typedef struct _SNode
{
	char data;
	struct _SNode *next;
}SNode;

typedef struct _Stack
{
	SNode * top;
}Stack;


void initStack(Stack *s);
int isStackEmpty(Stack *s);
void Push(Stack *s, char ch);
char Pop(Stack *s);

void resetStack(Stack *s);
char clearStack(Stack *s);

#endif // MYSTACK_H
