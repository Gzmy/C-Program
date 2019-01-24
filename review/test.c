#include <stdio.h>
#include <assert.h>

#define SQUARE( x ) (x) * (x)
//#define PRINT(FOMAT, VAL) printf("the val is "FOMAT"\n", VAL);

#define MAX(a, b) ((a) > (b) ? (a) : (b))

//#define __DEBUG__

int main()
{
	int i = 0;
	int arr[10] = {0};
	for(; i < 10; i++) {
		arr[i] = i;
#ifdef __DEBUG__
		printf("%d\n", arr[i]);
#endif
	}
	//assert(argc == 2);
	//int array[ARRAY_SIZE];
	//int i = 0;
	//for(; i < ARRAY_SIZE; i++) {
	//	array[i] = i;
	//}

	//for(i = 0; i < ARRAY_SIZE; i++) {
	//	printf("%d ", array[i]);
	//}
	//printf("\n");

	//int x = 5;
	//int y = 8;
	//int z = MAX(x++, y++);

	//printf("x = %d, y = %d, z = %d\n", x, y, z);
	//PRINT("%d", 10);
	//char *p = "hello""gzy\n";
	//printf("%s", p);
	//printf("%d\n", SQUARE(5+1));
	//printf("file:%s, line:%d, date:%s, time:%s\n", __FILE__, __LINE__, __DATE__, __TIME__);
	//int i = 0;
	//for(; i < 10; i++) {
	//	printf("%d ", i);
	//}
	//extern void print(char *str);
	//extern int g_val;
	//printf("%d\n", g_val);
	//print("hello gzy\n");
	return 0;
}
