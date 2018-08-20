#include"mystack.h"
#include<stdlib.h>


void initStack(Stack *s)
{
	s->top = (SNode *)malloc(sizeof(SNode));
	s->top->next = NULL;
}

int isStackEmpty(Stack *s)
{
	return s->top->next == NULL;
}

void Push(Stack *s, char ch)
{
	SNode * tmp = (SNode *)malloc(sizeof(SNode));
	tmp->data = ch;
	tmp->next = s->top->next;
	s->top->next = tmp;
}

char Pop(Stack *s)
{
	//    SNode * t = (SNode *)malloc(sizeof(SNode));
	//    t = s->top->next;
	SNode *t = s->top->next;
	char ch= t->data;
	s->top->next = t->next;
	free(t);
	
	return ch;
}


void resetStack(Stack *s)
{
	while (!isStackEmpty(s))
	{
		Pop(s);
	}
}
char clearStack(Stack *s)
{
	resetStack(s);
	free(s->top);
}
