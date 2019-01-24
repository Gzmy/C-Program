#include <stdio.h>
#include <stdio.h>

int main()
{
	int a = 10;
	int *p = &a;
	free(p);
	return 0;
}
