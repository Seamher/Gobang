#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 5
#define COL 5
void menu()
{
	printf("********************************************************\n");
	printf("*********************五    子    棋*********************\n");
	printf("********************************************************\n");
	printf("******开始游戏请输入1              结束游戏请输入0******\n");
	printf("********************************************************\n");
}
void Initboard(char board[ROW][COL],int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void Displayboard(char board[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
		}
		printf("\n");
	}
}
void Playermove(char board[ROW][COL], int row, int col)
{
	int x, y;
	printf("您的回合\n");
	while (1)
	{
		printf("请输入要下的坐标:");
		scanf_s("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else {
				printf("该坐标已被占用，请重新输入╥﹏╥\n");
			}
		}
		else {
			printf("非法坐标，请重新输入╥﹏╥\n");
		}
	}
}
void Computermove(char board[ROW][COL], int row, int col)
{
	int x, y;
	printf("电脑回合\n");
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}
int Isp(char board[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}
char Judgement(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] == board[i][3] && board[i][3] == board[i][4] && board[i][1] != ' ')
		{
			return board[i][1];
		}
	}
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] == board[3][i] && board[3][i] == board[4][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == board[3][3] && board[3][3] == board[4][4] && board[1][1] != ' ')
	{
		return board[2][2];
	}
	if (board[4][0] == board[3][1] && board[3][1] == board[2][2] && board[2][2] == board[1][3] && board[1][3] == board[0][4] && board[3][1] != ' ')
	{
		return board[2][2];
	}
	if (Isp(board, ROW, COL) == 1)
	{
		return 'P';
	}
	return 'C';
}
void game()
{
	char flag = 0;
	char board[ROW][COL];
	Initboard(board, ROW, COL);
	Displayboard(board, ROW, COL);
	while (1)
	{
		Playermove(board, ROW, COL);
		Displayboard(board, ROW, COL);
		flag = Judgement(board, ROW, COL);
		if (flag != 'C')
		{
			break;
		}
		Computermove(board, ROW, COL);
		Displayboard(board, ROW, COL);
		flag = Judgement(board, ROW, COL);
		if (flag != 'C')
		{
			break;
		}
	}
	if (flag == '*')
	{
		printf("你赢啦！(≧y≦)/\n");
	}
	else if (flag == '#')
	{
		printf("你输了╥﹏╥\n");
	}
	else printf("流局╥﹏╥\n");
}
void choose()
{
	srand((unsigned int)time(NULL));
	int num;
	do
	{
		menu();
		printf("                         请输入");
		scanf_s("%d", &num);
		switch (num)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:printf("输入错误，请重新输入\n");
			break;
		}
	} while (num);
}
int main()
{
	choose();
	return 0;
}