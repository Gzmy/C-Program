/*
 * 如十进制数123表达为16进制时只包含两位数7、11（B），
 * 用八进制表示为三位数1、7、3，按不同进制表达时，各个位数的和也不同，
 * 如上述例子中十六进制和八进制中各位数的和分别是18和11,。
 * 小B感兴趣的是，一个数A如果按2到A-1进制表达时，各个位数之和的均值是多少？
 * 她希望你能帮她解决这个问题？ 所有的计算均基于十进制进行，结果也用十进制表示为不可约简的分数形式。
 * 输入：5			3
 * 输出：7/3		2/1
 */

#include <stdio.h>

int get_1(int input, int i)
{
	int sum = 0;
	while(input)
	{
		sum += input%i;
		input /= i;
	}

	return sum;
}

int get_2(int a, int b)//求最大公约数
{
	while(a%b != 0)
	{
		int c = a % b;
		a = b;
		b = c;
	}
	return b;
}

int main()
{
	int input, i;
	while(scanf("%d", &input) != EOF)
	{
		int sum = 0, tmp, mu;
		for(i = 2; i < input; i++)
		{
			sum += get_1(input, i);
		}

		if(input - 2 == 0)
			printf("1/1\n");
		else
		{
			tmp = get_2(sum, input-2);
			sum /= tmp;
			mu = (input-2)/tmp;
			printf("%d/%d\n",sum, mu);//输出约分后的答案
		}
	}
	return 0;
}
