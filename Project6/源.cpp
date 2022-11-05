#include <stdio.h>

#define ROW 20
#define COL 20
void menu()
{
	printf("********************************************************\n");
	printf("*********************��    ��    ��*********************\n");
	printf("********************************************************\n");
	printf("******��ʼ��Ϸ������1              ������Ϸ������0******\n");
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
void game()
{
	char board[ROW][COL];
	Initboard(board, ROW, COL);
	Displayboard(board, ROW, COL);
}
void choose()
{
	int num;
	do
	{
		menu();
		printf("                         ������");
		scanf_s("%d", &num);
		switch (num)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:printf("�����������������\n");
			break;
		}
	} while (num);
}
int main()
{
	choose();
	return 0;
}