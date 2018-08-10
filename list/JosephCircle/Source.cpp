#include<stdio.h>
#include<stdlib.h>

typedef int DataType;

typedef struct Node
{
	DataType data;
	struct Node* next;

}Node,*pNode;

pNode cur = NULL;
pNode pre = NULL;
pNode head = NULL;

pNode CreatNode(DataType num)
{
	for (int i = 1; i < num+1;i++)
	{
		pNode tmp = (pNode)malloc(sizeof(Node));
		if (tmp == NULL)
		{
			printf("out of memory !\n");
			exit(EXIT_FAILURE);
		}
		else
		{
			cur = tmp;
			cur->data = i;
			cur->next = NULL;
		}
		if (head == NULL)
		{
			head = cur;
		}
		else
		{
			pre->next = cur;
		}
		pre = cur;
	}
	cur->next = head;
	return head;
}

void JosphCircle(DataType num,DataType count)
{
	cur = CreatNode(num);

	for (int i = 1; i <= num+1-count;i++)
	{
		for (int j = 1; j < count;j++)
		{
			pre = cur;
			cur = cur->next;
		}
		printf("第%d个淘汰的是%d\n",i,cur->data);
		pre->next = cur->next;
		free(cur);
		cur = pre->next;
	}
	printf("最后活下来的是%d",cur->data);
}

int main()
{
	int number = 10;
	int count = 3;
	JosphCircle(10, 4);


	system("pause");
	return 0;
}