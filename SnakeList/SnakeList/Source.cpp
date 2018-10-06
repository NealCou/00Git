#include <iostream>
#include <conio.h>
#include <windows.h>
#include "Header.h"

using namespace std;

bool gameOver = false;
int width = 0;
int height = 0;
int /*x, y,*/ FruitX, FruitY, Score;

//int nTail, tailX[100], tailY[100];
pNode Head = new Node;
pNode Tail = new Node;

enum Direction
{
	STOP = 0, LEFT, RIGHT, UP, DOWN
};

Direction dir;

void Setup()
{
	gameOver = false;
	width = height = 20;
	Score = 0;
	FruitX = rand() % width;
	FruitY = rand() % height;

	Head->x = width / 2;
	Head->y = height / 2;
	Head->next = Head->pre = NULL;

	Tail = Head;
}

void Draw()
{
	system("cls");
	for (int i = 0; i <= width + 1; i++)
	{
		cout << "#";
	}
	cout << endl;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0)
			{
				cout << "#";
			}
			if (i == FruitY && j == FruitX)
			{
				cout << "F";
			}
			else
			{
				bool prints = false;

				for (pNode pd = Head; pd != NULL; pd = pd->next)
				{
					if (i == pd->y && j == pd->x)
					{
						prints = true;
						if (pd == Head)
						{
							cout << 'O';
						}
						else
						{
							cout << 'O';
						}

					}
				}

				if (!prints)
				{
					cout << " ";
				}
			}

			if (j == width - 1)
			{
				cout << "#";
			}
		}
		cout << endl;
	}
	for (int i = 0; i <= width + 1; i++)
	{
		cout << "#";
	}
	cout << "\nScore : " << Score << endl;
	Sleep(300);
}

void Input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
			//case ' ':
			//	dir = STOP;
			//	break;
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		default:
			break;
		}
	}
}

void Logic()
{
	//Move
	pNode pt = new Node;
	pt = Tail;
	while (pt != Head)
	{
		pt->x = pt->pre->x;
		pt->y = pt->pre->y;
		pt = pt->pre;
	}

	switch (dir)
	{
	case LEFT:
		Head->x--;
		if (Head->x < 0)
		{
			Head->x = width - 1;
		}
		break;
	case RIGHT:
		Head->x++;
		if (Head->x >= width)
		{
			Head->x = 0;
		}
		break;
	case UP:
		Head->y--;
		if (Head->y < 0)
		{
			Head->y = height - 1;
		}
		break;
	case DOWN:
		Head->y++;
		if (Head->y >= height)
		{
			Head->y = 0;
		}
		break;
	default:
		break;
	}

	// kill self
	for (pNode pc = Head->next; pc != NULL; pc = pc->next)
	{
		if (Head->x == pc->x && Head->y == pc->y)
		{
			gameOver = true;
			cout << "\nGame Over!!!" << endl;
			break;
		}
	}

	if (Head->x == FruitX && Head->y == FruitY)
	{
		Score += 10;
		FruitX = rand() % width;
		FruitY = rand() % height;
		pNode newNode = new Node;

		Tail->next = newNode;
		newNode->pre = Tail;
		newNode->next = NULL;
		Tail = newNode;
	}
}


int main()
{
	Setup();
	while (!gameOver)
	{
		Draw();
		Input();
		Logic();
	}


	cin.get();
	return 0;
}