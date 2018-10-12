#include "sweeper.h"

void InitBoard(char arr[ROWS][COLS], int rows, int cols, char set)
{
	int i, j;
	for(i = 0; i < rows; i++)
	{
		for(j = 0; j < cols; j++)
		{
			arr[i][j] = set;
		}
	}
}

void DisplayBoard(char arr[ROWS][COLS], int row, int col)
{
	int i, j;
	for(i = 0; i <= col; i++)
	{
		printf("%d", i);
	}
	printf("\n");
	for(i = 1; i <= row; i++)
	{
		printf("%d", i);
		for(j = 1; j <= col; j++)
		{
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}
	printf("------------------\n");
}

void SetMine(char arr[ROWS][COLS], int row, int col)
{
	int i, j;
	int count = EASY_COUNT;

	while(count)
	{
		i = rand()%row + 1;
		j = rand()%col + 1;
		if(arr[i][j] == '0')
		{
			arr[i][j] = '1';
			count--;
		}
	}
}

void OpenMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int x, int y)
{
	int ret = GetMineCount(mine, x, y);
	if(ret == 0)
	{
		show[x][y] = ' ';
		if(x-1>0 && y>0 && show[x-1][y]=='*')
			OpenMine(mine, show, row, col, x-1, y);
		if(x-1>0 && y+1<=col && show[x-1][y+1]=='*')
			OpenMine(mine, show, row, col, x-1, y+1);
		if(x>0 && y+1<=col && show[x][y+1] =='*')
			OpenMine(mine, show, row, col, x, y+1);
		if(x+1<=row && y+1<=col && show[x+1][y+1] == '*')
			OpenMine(mine, show, row, col, x+1, y+1);
		if(x+1<=row && y>0 && show[x+1][y] == '*')
			OpenMine(mine, show, row, col, x+1, y);
		if(x+1<=row && y-1>0 && show[x+1][y-1] == '*')
			OpenMine(mine, show, row, col, x+1, y-1);
		if(x>0 && y-1>0 && show[x][y-1] == '*')
			OpenMine(mine, show, row, col, x, y-1);
		if(x-1>0 && y-1>0 && show[x-1][y-1] == '*')
			OpenMine(mine, show, row, col, x-1, y-1);
	}
	else
	{
		show[x][y] = GetMineCount(mine, x, y);
	}
}

void FirstSafe(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x, y;
	int i = 1;
	while(i)
	{
		printf("输入坐标>");
		scanf("%d%d", &x, &y);
		if(x>=1 && x<=9 && y>=1 && y<=9)
		{
			if(mine[x][y] == '1')
			{
				mine[x][y] = '0';
				int count = GetMineCount(mine, x, y);
				show[x][y] = count + '0';//将周围雷显示出来
				while(i)
				{
					x = rand()%row + 1;
					y = rand()%col + 1;
					if(mine[x][y] == '0' && i == 1)
					{
						mine[x][y] = '1';
						i--;
					}
					else
						continue;
				}
			}
			else
				break;
		}
		else
		{
			printf("重新输入:");
		}
	}
	int count = GetMineCount(mine, x, y);
	show[x][y] = count + '0';
	DisplayBoard(show, row, col);
}

static int IsWin(char arr[ROWS][COLS], int row, int col)
{
	int i, j, count;
	for(i = 1; i <= row; i++)
	{
		for(j = 1; j <= col; j++)
		{
			if(arr[i][j] == '*')
				count++;
		}
	}

	return count;
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x, y;
	while(1)
	{
		printf("输入坐标>");
		scanf("%d%d", &x, &y);
		if(x>=1 && x<=9 && y>=1 && y<=9)
		{
			if(mine[x][y] == '1')
			{
				printf("恭喜你被炸死了\n");
				DisplayBoard(mine, row, col);
				break;
			}
			else
			{
				int count = GetMineCount(mine, x, y);
				show[x][y] = count + '0';
				DisplayBoard(show, row, col);
				if(IsWin(show, row, col) == EASY_COUNT)
					break;
			}
		}
		else
		{
			printf("坐标不合法,重新输入:");
		}
	}

	if(IsWin(show, row, col) == EASY_COUNT)
	{
		printf("恭喜你,排雷成功\n");
		DisplayBoard(mine, row, col);
	}
}

int GetMineCount(char mine[ROWS][COLS], int x, int y)
{
	return (mine[x][y-1]+
			mine[x][y-2]+
			mine[x-1][y-1]+
			mine[x-1][y]+
			mine[x-1][y+1]+
			mine[x+1][y-1]+
			mine[x+1][y]+
			mine[x+1][y+1] - '0'*8);
}



