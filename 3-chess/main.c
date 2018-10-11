#include "chess.h"

void menu()
{
	printf("*****************\n");
	printf("*****1.play******\n");
	printf("*****0.exit******\n");
	printf("*****************\n");
}

void game()
{
	int ret = 0;
	char arr[ROW][COL] = {0};
	InitBoard(arr, ROW, COL);
	Display(arr, ROW, COL);
	while(1)
	{
		PlayerMove(arr, ROW, COL);
		ret = IsWin(arr, ROW, COL);
		Display(arr, ROW, COL);
		if(ret != J)
			break;
		ComputerMove(arr, ROW, COL);
		ret = IsWin(arr, ROW, COL);
		Display(arr, ROW, COL);
		if(ret != J)
			break;
	}

	if(ret == 'X')
		printf("玩家赢\n");
	else if(ret == 'O')
		printf("电脑赢\n");
	else
		printf("平局\n");
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
				printf("输入错误,请重新输入!\n");
				break;
		}
	}while(input);
	return 0;
}
