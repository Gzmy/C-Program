#include "sweeper.h"

void menu()
{
	printf("*******************\n");
	printf("****** 1.play *****\n");
	printf("****** 0.exit *****\n");
	printf("*******************\n");
}

void game()
{
	char mine[ROWS][COLS] = {0};
	char show[ROWS][COLS] = {0};
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	//DisplayBoard(show, ROW, COL);
	SetMine(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);
	FirstSafe(mine, show, ROW, COL);
	FindMine(mine, show, ROW, COL);
}

int main()
{
	int input;
	srand((unsigned)time(NULL));
	do
	{
		menu();
		printf("请选择>");
		scanf("%d", &input);
		switch(input)
		{
			case 1:
				game();
				break;
			case 0:
				printf("退出游戏\n");
				break;
			default:
				printf("输入错误,请重新选择>");
				break;
		}
	}while(input);
	return 0;
}
