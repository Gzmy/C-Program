#include "chess.h"

void InitBoard(char arr[ROW][COL], int row, int col)//初始化,每个位置是空格
{
	int i, j;
	for(i = 0; i < row; i++)
	{
		for(j = 0; j < col; j++)
		{
			arr[i][j] = ' ';
		}
	}
}

void Display(char arr[ROW][COL], int row, int col)
{
	int i, j;
	for(i = 0; i < row; i++)
	{
		if(i == 0)
		{
			for(j = 0; j <= col; j++)
				printf("---");
			printf("\n");
		}
		for(j = 0; j < col; j++)
		{
			printf("|");
			printf(" %c ", arr[i][j]);
			if(j == col - 1)
				printf("|");
		}
		printf("\n");
		if(i < row - 1)
		{
			for(j = 0; j < col; j++)
			{
				printf("|");
				printf("---");
				if(j == col - 1)
					printf("|");
			}
			printf("\n");
		}
		//printf("\n");
		if(i == row - 1)
		{
			for(j = 0; j <= col; j++)
				printf("---");
			printf("\n");
		}
	}
}

void PlayerMove(char arr[ROW][COL], int row, int col)
{
	int x, y;
	printf("玩家走\n");
	while(1)
	{
		printf("请输入坐标>");
		scanf("%d%d", &x, &y);
		if(x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if(arr[x-1][y-1] == ' ')
			{
				arr[x-1][y-1] = 'X';
				break;
			}
			else
			{
				printf("坐标被占用\n");
			}
		}
		else
		{
			printf("坐标输入不合法,重新输入.");
		}
	}
}

void ComputerMove(char arr[ROW][COL], int row, int col)
{
	int x, y;
	printf("电脑走>\n");
	while(1)
	{
		x = rand()%ROW;
		y = rand()%COL;
		if(arr[x][y] == ' ')
		{
			arr[x][y] = 'O';
			break;
		}
	}
}

static IsFull(char arr[ROW][COL], int row, int col)
{
	int i, j;
	for(i = 0; i < row; i++)
	{
		for(j = 0; j < col; j++)
		{
			if(arr[i][j] == ' ')
				return 0;
		}
	}

	return 1;
}


char IsWin(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	for(i = 0; i < row; i++)//看行是否一样
	{
		if(arr[i][0] == arr[i][1] && arr[i][0] == arr[i][2] && arr[i][0] != ' ')
			return arr[i][0];
	}

	for(i = 0; i < col; i++)//看列是否一样
	{
		if(arr[0][i] == arr[1][i] && arr[0][i] == arr[2][i] && arr[0][i] != ' ')
			return arr[0][i];
	}

	if(arr[0][0] == arr[1][1] && arr[0][0] == arr[2][2] && arr[0][0] != ' ')
		return arr[1][1];
	if(arr[0][2] == arr[1][1] && arr[0][2] == arr[2][0] && arr[0][2] != ' ')
		return arr[1][1];

	if(IsFull(arr, row, col))
		return P;

	return J;
}


