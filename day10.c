#include <stdio.h>

int f(int input)
{
	int sum = 0;
	while(input)
	{
		sum += input%10;
		input /= 10;
	}
	return sum;
}

int g(int input)
{
	int sum = 0;
	while(input)
	{
		if((input & 1) == 1)
			sum++;
		input >>= 1;
	}
	return sum;
}

int main()
{
	int input, sum = 0, i;
	scanf("%d", &input);
	for(i = 1; i <= input; i++)
	{
		if(f(i) == g(i))
			sum++;
	}
	printf("%d\n", sum);
	return 0;
}
