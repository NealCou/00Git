#include <iostream>
#include <conio.h>

using namespace std;

bool gameOver = false;
int width = 0;
int height = 0;
int x, y, FruitX, FruitY, Score;

int nTail, tailX[100], tailY[100];

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
	x = width / 2;
	y = height / 2;
	FruitX = rand() % width;
	FruitY = rand() % height;
	nTail = 1;
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
			if (i == y && j == x)
			{
				cout << "O";
			}
			else if (i == FruitY && j == FruitX)
			{
				cout << "F";
			}
			else
			{
				bool prints = false;

				for (int k = 1; k < nTail; k++)
				{
					if (i == tailY[k] && j == tailX[k])
					{
						prints = true;
						cout << 'o';
						break;
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
}

void Input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case ' ':
			dir = STOP;
			break;
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

	switch (dir)
	{
	case STOP:
		break;
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	default:
		break;
	}

	int preX = tailX[0];
	int preY = tailY[0];
	tailX[0] = x;
	tailY[0] = y;
	for (int i = 1; i < nTail; i++)
	{
		int pre2X = tailX[i];
		int pre2Y = tailY[i];
		tailX[i] = preX;
		tailY[i] = preY;
		preX = pre2X;
		preY = pre2Y;
	}

	// kill self
	for (int k = 1; k < nTail; k++)
	{
		if (x == tailX[k] && y == tailY[k])
		{
			gameOver = true;
			cout << "\nGame Over!!!" << endl;
			break;
		}
	}

	if (x == FruitX && y == FruitY)
	{
		Score += 10;
		FruitX = rand() % width;
		FruitY = rand() % height;
		nTail++;
	}
	if (x >= width)
	{
		x = 0;
	}
	else if (x < 0)
	{
		x = width - 1;
	}

	if (y >= height)
	{
		y = 0;
	}
	else if (y < 0)
	{
		y = height - 1;
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