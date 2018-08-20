#ifndef MYSTACK_H
#define MYSTACK_H
#include "BstTree.h"
typedef struct _SNode
{
	TreeNode* data;
    struct _SNode *next;
}SNode;

typedef struct _Stack
{
    SNode * top;
}Stack;

void initStack(Stack * s);
int isStackEmpty(Stack *s);
void Push(Stack *s,TreeNode *ch);
TreeNode* Pop(Stack *s);

//void resetStack(Stack *s);
//TreeNode* clearStack(Stack *s);

#endif // MYSTACK_H
