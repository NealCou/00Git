#include <stdio.h>
#include"mystack.h"


int main(int argc, char *argv[])
{
	Stack ps;
	initStack(&ps);
	for (char ch = 'A'; ch <= 'Z'; ch++)
	{
		Push(&ps, ch);
	}
	//resetStack(&ps);
	while (!isStackEmpty(&ps))
	{
		printf("%c ", Pop(&ps));
	}
	system("pause");
	return 0;
}
