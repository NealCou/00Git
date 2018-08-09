#include <stdio.h>
#include<time.h>
#include<stdlib.h>
#include"list.h"

int main(int argc, char *argv[])
{
	Node * head = creatList();
	traverseList(head);

	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		insertList(head, rand() % 100);
	}
	traverseList(head);
	int len = lenList(head);
	printf("\n%d\n", len);



	Node * pfind = searchList(head, 8);
	if (pfind != NULL)
	{
		printf("find in the list!!!\n");
		deleteList(head, pfind);
		traverseList(head);
	}

	printf("/n after sort!\n");
	popSortList(head);
	traverseList(head);


	return 0;
}
