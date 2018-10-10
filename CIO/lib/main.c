/*hello user*/
#include <stdio.h>
#include "add.h"
#include "sub.h"
#include "mul.h"

int main()
{
	int a = 10;
	int b = 20;
	printf("%d + %d = %d\n", a, b, add(a, b));
	printf("%d - %d = %d\n", a, b, sub(a, b));
	printf("%d * %d = %d\n", a, b, mul(a, b));
	return 0;
}
