#include"stack.h"


void initStack(Stack *s, int size)
{
	s->_len = size;
	s->_top = 0;
	s->_space = (char *)malloc(sizeof(char)*size);
}

int isStackFull(Stack *s)
{
	return s->_top == s->_len;
}

int isStackEmpty(Stack *s)
{
	return s->_top == 0;
}

void Push(Stack *s, char ch)
{
	s->_space[s->_top] = ch;
	s->_top++;
}

char Pop(Stack *s)
{
	return s->_space[--s->_top];
}

void resetStack(Stack *s)
{
	s->_top = 0;
}

void clearStack(Stack *s)
{
	free(s->_len);
}
