#include <stdio.h>
#include"stack.h"

int main(int argc, char *argv[])
{
	Stack ps;
	initStack(&ps, 100);
	for (char ch = 'A'; ch <= 'Z'; ch++)
	{
		Push(&ps, ch);
	}
	while (!isStackEmpty(&ps))
	{
		printf("%c ", Pop(&ps));
	}
	system("pause");
	return 0;

}
