#pragma once
#ifndef  _STACK_H_
#define  _STACK_H_
#include<stdio.h>
#include<stdlib.h>

typedef struct _Stack
{
	int _len;
	int _top;
	char *_space;
}Stack;

void initStack(Stack *s, int size);
int isStackFull(Stack *s);
int isStackEmpty(Stack *s);
void Push(Stack *s, char ch);
char Pop(Stack *s);

void resetStack(Stack *s);
void clearStack(Stack *s);



#endif // STACK_H
