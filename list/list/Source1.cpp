#include <stdio.h>
#include<time.h>
#include<stdlib.h>
#include"list.h"

int main(int argc, char *argv[])
{
	
	printf("// 2.5.2 �ж�һ�������Ƿ��л�;\n");
	Node *head2 = creatList();
	traverseList(head2);

	printf("have some num!\n");
	for (int i = 0; i < 11; i++)
	{
		insertList(head2, i);
	}

	Node * t = head2;
	while (t->next)
	{
		t = t->next;
	}
	t->next = head2->next->next->next;

	/*traverseList(head2);*/
	Node *x, *y;
	x = y = head2;
	while (y)
	{
		x = x->next;
		y = y->next;
		if (!y) break;
		y = y->next;

		if (x == y)
		{
			printf("\n�������л���\n");
			break;
		}
	}


	printf("\n\n// 2.5.3 ��������м�ڵ㣬ֻ��һ��ѭ����\n");
	Node *head3 = creatList();
	traverseList(head3);

	printf("have some num!\n");
	for (int i = 0; i < 10;i++)
	{
		insertList(head3, i);		
	}
	traverseList(head3);

	Node *p, *q;
	p = head3;
	q = head3;

	while (q)
	{
		p = p->next;
		q = q->next;
		if(!q)
			break;
		q = q->next;	
	}
	printf("\n�м�ڵ�Ϊ��%2d\n", p->data);

	
	

	system("pause");
	return 0;
}